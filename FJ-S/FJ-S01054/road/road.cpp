#include<bits/stdc++.h>
using namespace std;
const int inf = 2e6+5;
long long n,m,k,y[10005];
struct edge{
	long long u,v,w;
}a[inf];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[10005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w;
	}//m
	long long t=m;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)cin>>y[j];
		for(int j=1;j<=n-1;j++){
			for(int p=j+1;p<=n;p++){
				t++;
				a[t].u=j,a[t].v=p,a[t].w=x+y[j]+y[p];
			}
		}
	}//nk+n^2k
	sort(a+1,a+t+1,cmp);//tlogt
	long long ans=0,tot=1;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=t;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		ans+=w;
		tot++;
		if(fa[fv]!=fa[fu])fa[fv]=fa[fu];
		else fa[fv]=fa[fu];
		if(tot==n)break;
	}//tlogt
	cout<<ans<<endl;
	return 0;
}
