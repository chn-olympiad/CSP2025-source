#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,cnt;
ll ans;
bool b[10010];
ll sum[10010][10010];
int c[110],a[110][10010],f[10010];
int fir[10010],to[1000100],nex[1000100],num[1000100];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
void add(int u,int v,int w){
	cnt++;
	nex[cnt]=fir[u];
	fir[u]=cnt;
	to[cnt]=v;
	num[cnt]=w;
}
void dfs(int u,int fa){
	if(b[u])return;
	b[u]=1;
	f[u]=fa;
	for(int i=fir[u];i;i=nex[i]){
		int v=to[i],w=num[i];
		if(v!=fa){
			sum[u][v]=sum[v][u]=w;
			dfs(v,u);
		}
	}
}
void bfs(int s){
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		b[u]=1;
		for(int i=fir[u];i;i=nex[i]){
			int v=to[i],w=num[i];
			if(!b[v]){
				b[v]=1;
				if(sum[f[v]][v]>w){
					sum[f[v]][v]=sum[v][f[v]]=w;
					f[v]=u;
//					cout<<sum[u][v]<<" "<<u<<" "<<v<<"---"<<endl;
				}
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
//			add(n+i,j,a[i][j]);
//			add(j,n+i,a[i][j]);
		}
	}
	memset(sum,0x7f,sizeof(sum));
	dfs(1,0);
	memset(b,0,sizeof(b));
	bfs(1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i]==j){
//				cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
				ans+=sum[i][j];
			}
		}
	}
	cout<<ans;
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
