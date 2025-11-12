#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e6+1e2;
struct node{
	int x,y,z,ii;
}w[N];
bool cmp(node x,node y){
	return x.z<y.z;
}
int f[1005];
int get(int x){
	if(!f[x])return x;
	return f[x]=get(f[x]);
}
int a[11][10005],c[11],vv[11],n,m,k,cnt,h=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>w[i].x>>w[i].y>>w[i].z;
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i],h=max(h,c[i]);
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k){
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++){
				int ww=1e9,ll=0;
				for(int i=1;i<=k;i++)
					if(a[i][u]+a[i][v]<ww)
						ww=a[i][u]+a[i][v],ll=i;
				w[++cnt]={u,v,ww,ll};
			}
	}
	int tot=0,ans=0;
	sort(w+1,w+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=get(w[i].x),y=get(w[i].y);
		if(x==y)continue;
		int hh=get(w[i+1].x),gg=get(w[i+1].y);
		if(w[i].z+c[w[i].ii]*(vv[w[i].ii]==0)>w[i+1].z&&hh!=gg)continue;
		tot++,f[x]=y,ans+=w[i].z+c[w[i].ii]*(vv[w[i].ii]==0),vv[w[i].ii]=1;
		if(tot>=n-1)break;
	}
	cout<<ans;
}