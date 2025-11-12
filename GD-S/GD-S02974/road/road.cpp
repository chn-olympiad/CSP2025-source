#include <bits/stdc++.h>
using namespace std;

const int MAXn = 1e4+5;
int n,m,k,c[MAXn];
int a[15][MAXn];

int Node[MAXn];
struct Edge{
	int u;
	int v;
	int w;
	
	bool operator<(const Edge& other)const{
		return w > other.w;
	}
};
Edge nEdge(int u,int v,int w){
	Edge tmp;
	tmp.u = u;
	tmp.v = v;
	tmp.w = w;
	return tmp;
}

priority_queue<Edge> pq1;
priority_queue<Edge> pq2;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		pq1.push(nEdge(u,v,w));
		pq2.push(nEdge(u,v,w));
	}
	for (int i=1;i<=n;i++)
		Node[i] = i;
	
	int ans1=0;
	while (!pq1.empty()){
		Edge u = pq1.top();
		pq1.pop();
		
		if (Node[u.u] == Node[u.v]) continue;
		for (int i=1;i<=n;i++){
			if (Node[i] != Node[u.u]) continue;
			if (i == u.u) continue;
			Node[i] = Node[u.v];
		}
		Node[u.u] =  Node[u.v];
		ans1 += u.w;
	}
	
	int ans2=0;int pn=n;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=pn;j++){
			cin>>a[i][j];
		}
		
		if (c[i] > ans1) continue;
		ans2 += c[i];
		n++;
		for (int j=1;j<=pn;j++){
			pq2.push(nEdge(n,j,a[i][j]));
		}
	}
	
	for (int i=1;i<=n;i++)
		Node[i] = i;
	while (!pq2.empty()){
		Edge u = pq2.top();
		pq2.pop();
		
		
		if (Node[u.u] == Node[u.v]) continue;
		for (int i=1;i<=n;i++){
			if (Node[i] != Node[u.u]) continue;
			if (i == u.u) continue;
			Node[i] = Node[u.v];
		}
		Node[u.u] =  Node[u.v];
		
		ans2 += u.w;
	}
	
	cout<<min(ans1,ans2);
	
	
	
	
	
	
	
	
	return 0;
} 

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
