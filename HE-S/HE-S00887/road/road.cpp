#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
struct rode{
	int u,v,w;
}a[100010];
int fa[100010];
bool cmp(rode a,rode b){
	return a.w<b.w;
}
int c[30];
int b[25][100010];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	for(int i=1;i<=n;i++) fa[i]=i;
 	sort(a+1,a+1+m,cmp);
 	int cnt=0;
 	for(int i=1;i<=m;i++){
 		if(find(fa[a[i].u])==find(fa[a[i].v])) continue;
 		cnt++;
 		fa[find(a[i].u)]=find(fa[a[i].v]);
 		sum+=a[i].w;
 		if(cnt==n-1) break;
	 }
	 cout<<sum<<endl;
	 return 0;
}
