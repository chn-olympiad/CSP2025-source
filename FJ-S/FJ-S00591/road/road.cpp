#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define M 1000010
#define int long long
int n,m,f[N],K,a[11][N],siz[N],ans,c[11],sk,cnt;
struct node{
	int x,y,z;
}E[M],e[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.z<b.z;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	int i,j,s;
	cin>>n>>m>>K;
	for(i=1;i<=m;i++)cin>>E[i].x>>E[i].y>>E[i].z;
	sort(E+1,E+1+m,cmp);
	int k=0;
	for(i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(i=1;i<=m;i++){
		int x=E[i].x,y=E[i].y,z=E[i].z;
		int u=find(x),v=find(y);
		if(u!=v){
			if(siz[u]<siz[v])f[u]=v,siz[v]+=siz[u];
			else f[v]=u,siz[u]+=siz[v];
			k++;
			ans+=z;
			e[k].x=x,e[k].y=y,e[k].z=z;
		}
		if(k==n-1)break;
	}for(i=1;i<=K;i++){
		cin>>c[i];
		for(j=1;j<=n;j++)cin>>a[i][j],e[++k].x=i+n,e[k].y=j,e[k].z=a[i][j];
	}
	cnt=k;
	sort(e+1,e+1+cnt,cmp);
	for(s=1;s<(1<<K);s++){
		sk=0;
		for(i=1;i<=K;i++){
			if(s&(1<<i))sk+=c[i];
		}
		for(i=1;i<=n+K;i++)f[i]=i,siz[i]=1;
		k=0;
		for(i=1;i<=cnt;i++){
			int x=e[i].x,y=e[i].y,z=e[i].z;
			if(x>n&&!(s&(1<<(x-n))))continue;
			int u=find(x),v=find(y);
			if(u!=v){
				if(siz[u]<siz[v])f[u]=v,siz[v]+=siz[u];
				else f[v]=u,siz[u]+=siz[v];
				k++;
				sk+=z;
			}
			if(k==n+m-1)break;
		}
		ans=min(ans,sk);
	}
	cout<<ans;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
