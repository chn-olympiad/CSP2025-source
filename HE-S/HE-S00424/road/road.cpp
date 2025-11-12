#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1000;
int n,m,k;
int u,v,w;
int len[N],to[N],next1[N],p[N];
int d[N],k,a[15][100010],s=1,ans;
bool f[N];
void add(int x,int y,int z){
	k++;
	len[k]=z;
	to[k]=y;
	next1[k]=p[x];
	p[x]=k;
}
void spfa(){
	memset(d,0,sizeof(d));
	d[1]=0;
	f[1]=true;
	queue<int > q;
	while(!q.empty()){
		int x=q.front();
		for(int i=to[x];i!=0;i=next1[i]){
			int j=p[x];
			if(d[x]>d[i]+len[j]){
				d[x]=d[i]+len[j];
				if(!f[j]){
					q.push(j);
					f[j]=true;
				}
			}
		}
		q.pop();
		f[x]=false;
	}
	for(int i=2;i<=n;i++){
		if(d[i]==0){
			ans+=a[s]+a[1]+a[i];
			s++;
		}
		ans+=d[i];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}
/*

*/
