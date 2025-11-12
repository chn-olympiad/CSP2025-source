#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+3,M=1e6+3;
int n,m,k,f[N],cnt,d[N],g[N],h[N];
int c[11],a[11][N],mn[11],l[11];
ll ans;
struct node{
	int x,y,z;
}b[M],t[M];
bool cmp(node a,node b){
	return a.z<b.z;
}
int fnd(int x){
	return f[x]==x?x:f[x]=fnd(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>b[i].x>>b[i].y>>b[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		mn[i]=2e9;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<mn[i])mn[i]=a[i][j],l[i]=j;
		}
	}
	sort(b+1,b+m+1,cmp);
	iota(f,f+n+1,0);
	for(int i=1;i<=m;i++){
		int fx=fnd(b[i].x),fy=fnd(b[i].y);
		if(fx==fy)continue;
		ans+=b[i].z,f[fx]=fy,b[++cnt]=b[i];
	}
	for(int i=1;i<(1<<k);i++){
		int p=n,q=cnt;
		ll s=0;
		for(int j=1;j<=cnt;j++)t[j]=b[j];
		for(int j=1;j<=n;j++)g[j]=2e9;
		for(int j=1;j<=k;j++){
			if((i>>j-1)&1){
				p++,s+=c[j];
				for(int l=1;l<=n;l++)if(a[j][l]<g[l])g[l]=a[j][l],h[l]=p;
				t[++q]={p,l[j],mn[j]};
			}
		}
		for(int j=1;j<=n;j++)t[++q]={h[j],j,g[j]};
		stable_sort(t+1,t+q+1,cmp);
		iota(f,f+p+1,0);
		for(int j=1;j<=q;j++){
			int fx=fnd(t[j].x),fy=fnd(t[j].y);
			if(fx==fy)continue;
			s+=t[j].z,f[fx]=fy;
			if(s>=ans)break;
		}
		ans=min(ans,s);
	}
	cout<<ans;
}
