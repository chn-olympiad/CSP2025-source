#include<bits/stdc++.h>
using namespace std;
long long const N=1e7+9;
long long n,m,k,u,v,w,c[N],a[N],f[N],ans=0,h=0;
long long find(long long x) {
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
struct stu {
	long long x,y,z,bh;
}x[N];
bool gz(stu x,stu y) {
	if(x.z==y.z) return x.bh>y.bh;
	return x.z<y.z;
}
map<long long,long long> o;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) f[i]=i;
	for(long long i=1;i<=m;i++) {
		cin>>u>>v>>w;
		x[i].x=u;
		x[i].y=v;
		x[i].z=w;
		x[i].bh=i;
	}
	for(long long i=1;i<=k;i++) {
		cin>>c[i];
		for(long long j=1;j<=n;j++) {
			cin>>a[j];
		}
		for(long long j=1;j<=n;j++) {
			for(long long k=j+1;k<=n;k++) {
				x[++m].x=j;
				x[m].y=k;
				x[m].z=a[j]+a[k]+c[i];
				x[m].bh=m;
				o[m]=i;
			}
		}
	}
	sort(x+1,x+m+1,gz);
	for(long long i=1;i<=m;i++) {
		long long z=x[i].x,y=x[i].y;
		if(find(z)==find(y)) continue;
		c[o[x[i].bh]]=0;
		f[find(z)]=find(y);
		ans+=x[i].z;
		h++;
		if(h==n-1) break;
	}
	cout<<ans;
	return 0;
}