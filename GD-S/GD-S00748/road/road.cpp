#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int n,m,ans;
int g[N][N],d[N];

struct node{
	int to,w;
};

vector<node> v[N];

bool operator < (node a,node b){
	return a.w > b.w;
}

int find(){
	int fa = find[fa];
	return find(fa);
} 
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k;
    cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    for(int i = 1; i <= k; i++){
    	int c;
    	cin >> c;
		for(int j = 1; j <= n; j++){
			cin >> d[j];
		}
		for(int p = 1; p <= n; p++){
			for(int q = 1; q <= n; q++){
				g[p][q] = min(g[p][q],c+d[p]+d[q]);
			}
		}
	}
	for(int p = 1; p <= n-1; p++){
		for(int q = p+1; q <= n; q++){
			q[p].push({q,g[p][q]});
		}
	}
	sort(v+1,v+1+);
	//kruskal()
    //this is a minimum spanning tree
    return 0;
}
