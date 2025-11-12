#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,c[15],a[1001000],f[1000100];
struct ppp{int u,v,w,id,xz;}e[10010000];
bool p[15];
bool cmp(ppp x,ppp y){return x.w<y.w;}
int find(int k){
	if(f[k]==k)return k;
	return f[k]=find(f[k]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int x=m;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>a[j];
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				e[m].u=j;
				e[m].v=k;
				e[m].w=a[j]+a[k];
				e[m].id=m;
				e[m].xz=i;
				m++;
			}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fa=find(e[i].u);
		int fb=find(e[i].v);
		if(fa!=fb){
			if(e[i].id>x)
				if(!p[e[i].xz])
					ans+=c[e[i].xz],p[e[i].xz]=1;
			ans+=e[i].w,f[fa]=fb;
		}
	}
	cout<<ans;
	return 0;
}
