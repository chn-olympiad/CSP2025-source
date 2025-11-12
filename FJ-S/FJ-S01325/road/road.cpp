#include<bits/stdc++.h>
using namespace std;
long long f[10101],n,m,k,kk[11][10001],c[11],d,dd=1e9;
struct ll{
	long long u,v,w,s;
}a[2000001],b[2000001];
bool ok(ll a,ll b){
	return a.w<b.w;
}
bool obk(ll a,ll b){
	return a.s<b.s;
}
long long find(long long a){
	if(f[a]!=a)return find(f[a]);
	return a;
}
void dg(long long g,long long s){
	d=s;
	long long p=s;
	long long h=g;
	for(int i=1;i<=k;i++){
		if(c[i]==0){
			d+=kk[i][0];
			for(int j=1;j<=n;j++){
				b[++h].u=n+i;
				b[h].v=j;
				b[h].w=kk[i][j];
				b[h].s=h;
			}
			sort(b+1,b+1+h,ok);
			for(int j=1;j<=n+k;j++)f[j]=j;
			for(int j=1;j<=h;j++){
				long long x=find(b[j].u);
				long long y=find(b[j].v);
				if(x!=y){
					d+=b[j].w;
					f[x]=y;
				}
			}
			dd=min(dd,d);
			p+=kk[i][0];
			sort(b+1,b+1+h,obk);
			c[i]=1;
			dg(h,p);
			p=s;
			c[i]=0;
			for(int j=g+1;j<=h;j++){
				b[j].u=0;
				b[j].v=0;
				b[j].w=0;
				b[j].s=0;
			}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		a[i].s=i;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&kk[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		b[i].u=a[i].u;
		b[i].v=a[i].v;
		b[i].w=a[i].w;
		b[i].s=a[i].s;
	}
	dg(m,0);
	for(int i=1;i<=n+k;i++)f[i]=i;
	sort(a+1,a+1+m,ok);
	for(int i=1;i<=m;i++){
		long long x=find(a[i].u);
		long long y=find(a[i].v);
		if(x!=y){
			d+=a[i].w;
			f[x]=y;
		}
	}
	dd=min(dd,d);
	cout<<dd;
	return 0;
}

