#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10,M = 2e6 + 10;
typedef pair <int,pair <int,int> > PII;
int n,m,k;
//int h[N],e[M],ne[M],w[M],idx;
int g[N][N];
bool st[N];
int nw[N];
int ex[N][N];
int p[M];
//priority_queue <PII,vector <PII>,greater <PII> > heap;
//void add(int a,int b,int c){
//	e[++ idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx;
//}
//int find(int x){
//	if(p[x]) return p[x] = x;
//}
//void kruscal(){
//	for(int i = 1;i <= n + k;i ++) p[i] = i;
//	for(int i = 1;i <= n;i ++){
//		PII ta = heap.top();
//		heap.pop;
//		PII tb = heap.top();
//		heap.pop();
//		int a
//		if()
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(g,0x3f,sizeof g);
	for(int i = 1;i <= m;i ++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a][b] = g[b][a] = min(g[a][b],c);
//		heap.push({c,{a,b}});
	}
	for(int i = 1;i <= k;i ++){
		scanf("%d",&nw[i]);
		for(int j = 1;j <= n;j ++){
			int x;
			scanf("%d",&x);
			g[n + i][j] = g[j][n + i] = min(g[n + i][j],x);
//			heap.push({x,{n + i,j}});
		}
	}
//	kruscal();
	int res = 0;
	printf("%d\n",res);
	return 0;
}
