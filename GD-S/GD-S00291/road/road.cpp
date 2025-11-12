#include<bits/stdc++.h>
#define int long long
#define N 10025
using namespace std;
struct Nd{int x,y,z;}e[1500005];
bool cmp(Nd a1,Nd a2){return a1.z<a2.z;}
int n,m,k,c[13],d,f[N],t=0,cnt=0,ans=0;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1,a1,a2,a3;i<=m;i++){
		cin>>a1>>a2>>a3;
		e[++cnt]=(Nd){a1,a2,a3};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i],ans+=c[i];
		for(int j=1,d;j<=n;j++) cin>>d,e[++cnt]=(Nd){n+i,j,d};
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x==y) continue;
		f[x]=y,t++,ans+=e[i].z;
		if(t==n+k-1) break;
	}
	cout<<ans;
	return 0;
}
