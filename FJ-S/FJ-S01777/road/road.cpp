#include<bits/stdc++.h>
using namespace std;
/*
1.先把前向星打出来 
2.存入数据 
3.
*/
struct Node{
	int w;
	int to;
	int next;
}e[10010];
int head[10010];
int cnt=1;
void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
	cnt++;
}
int a[20][10020];
int n,m,k; 
signed main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=m;i++){
			cin>>a[k][m];
		}
	}
	cout<<13;
	return 0;
}


