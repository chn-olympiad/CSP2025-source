#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m,k;
int to[2*N],nxt[2*N],h[N],val[2*N],cnt=0;
int c[15][N];//新型城市 
bool vis[N];
void add(int a,int b,int c){
	to[cnt++]=b;
	val[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
//链式前向星 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	long long d=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		//无向边
		if(vis[v]==false){
			vis[v]=true;
			d+=w;	
		}
		
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	} 
	
	printf("%lld",d);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
