#include<bits/stdc++.h>
using namespace std;
const int bg=1e6+5;
int cnt,head[bg],nxt[bg*2],to[bg*2],c[bg];
//void add(int u,int v,int w){
//	to[++cnt]=v;
//	nxt[cnt]=head[u];
//	head[u]=cnt;
//	c[cnt]=w;
//}
int main(){
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		add(u,v,w);
		add()
	}
	return 0;
}
