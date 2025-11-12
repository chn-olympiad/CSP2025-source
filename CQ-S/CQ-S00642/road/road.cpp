#include<bits/stdc++.h>
using namespace std;
int f[100005],siz[100005],a[100005][2],n,m,cnt,ans,k;
struct node{
	int u,v,w,id;
}e[100005],tmp[100005];
void merge(int fx,int fy){
	if(siz[fx]<siz[fy])swap(fx,fy);
	f[fy]=fx;
	siz[fx]+=siz[fy];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=n;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	m=cnt;
	for(int i=1;i<=cnt;i++)e[i]=tmp[i];
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	for(int i=1;i<=m;i++)
	sort(e+1,e+m+1);
	for(int s=0;s<(1<<k);s++){
		int res=0;
		cnt=0;
		for(int i=1;i<=m;i++)tmp[++cnt]=e[i];
		for(int i=1;i<=k;i++)if(s&(1<<i-1))tmp[++cnt]=(node){i+n,1,a[i][1]};
		int ct=0;
		for(int i=1;i<=n+k;i++){
			f[i]=i;
			siz[i]=1;
		}
		int sz=n+__builtin_popcount(s);
		for(int i=1;i<=m;i++){
			if(e[i].id&&!(s&(1<<e[i].id-1)))continue;
			
		}
	}
	cout<<ans;
	return 0;
}
