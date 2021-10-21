#include <bits/stdc++.h>
#include <String>
#include <Vector>
using namespace std;

const int INF = 1e9;
const int N = 1e5+3;
int n=5;
vector<int> dis;
vector<int> prt;
vector<pair<int, int>> adj[N];

void add_undirected_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void dijkstra(int src) {
    dis.assign(n, INF);
    prt.assign(n, -1);
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>> > pq;  
    pq.push({0, src}); 
 
    dis[src] = 0;

    while (!pq.empty()) { 
        int v = pq.top().second; 
        pq.pop();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dis[u] > dis[v] + w) {
                dis[u] = dis[v] + w;
                pq.push({dis[u], u}); 
                prt[u] = v;
            }
        }
    }
}

int main() {
    add_undirected_edge( 0, 1, 10);
    add_undirected_edge( 0, 4, 30);
    add_undirected_edge( 1, 3, 13);
    add_undirected_edge( 3, 4, 5);
    add_undirected_edge( 1, 4, 40);
    add_undirected_edge( 4, 2, 20);

    string f;
    cout << "From : ";
    cin >> f;
    int ff;
    if (f=="Cairo"){ff=0;}
    else if (f=="Alex"){ff=1;}
    else if (f=="Aswan"){ ff=2;}
    else if (f=="Matrouh"){ff=3;}
    else if (f=="Sewa"){ff=4;}
    string t;

    cout << "To : ";
    cin >> t;
    int tt;
    
    if (t=="Cairo"){tt=0;}
    else if (t=="Alex"){tt=1;}
    else if (t=="Aswan"){tt=2;}
    else if (t=="Matrouh"){tt=3;}
    else if (t=="Sewa"){tt=4;}

    dijkstra(ff);
    
    cout << "Distance from : " << f << " to : "<< t << " equal : "<< dis[tt] << '\n'; 
    cout << "The path is : " ;
    /*for (int i = 0; i < prt.size(); i++) 
        cout << i << ' ' << prt[i] << '\n';*/
    int i=tt;
             if (tt==0){cout <<"Cairo"<<  " <- " ; }
        else if (tt==1){cout <<"Alex"<< " <- ";}
        else if (tt==2){cout <<"Aswan"<< " <- " ;}
        else if (tt==3){cout <<"Matrouh"<<  " <- " ;}
        else if (tt==4){cout <<"Sewa"<<  " <- " ;}

    while (i!=ff)
    {
             if (prt[i]==0){cout <<"Cairo"; }
        else if (prt[i]==1){cout <<"Alex" ;}
        else if (prt[i]==2){cout <<"Aswan";}
        else if (prt[i]==3){cout <<"Matrouh";}
        else if (prt[i]==4){cout <<"Sewa";}
        i=prt[i];
        if(i!=ff){cout << " <- " ;}

    }     
}
/*
9
14

*/
/*
Distance :
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14

Parent :
0 -1
1 0
2 1
3 2
4 5
5 6
6 7
7 0
8 2
*/
/*cout << '\n';
    cout << "Parent :\n";
    for (int i = 0; i < prt.size(); i++) 
        cout << i << ' ' << prt[i] << '\n'; 
    cout << '\n';
    //for (int i = 0; i < n; i++) 
    cout << "Enter the node :";
    cin >> n;
    int q;
    cout << "Enter the edge :";
    cin >> q;
    while (q > 0) {
        int u, v, w;
        cin >> u >> v >> w;
		q--;
	}*/