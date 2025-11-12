#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
ll n,m,k;
ll zz[20];
ll p[20],sz;
ll c[30],ans;
struct edge{
	ll x,y;
	ll w;
}e[3000020],a[20][20010];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll f[20020];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void Kruskal(){
	int cur=n-1+sz;
	ll sum=0;
	zz[0]=1;
	for(int i=1;i<=sz;i++){
		sum+=c[p[sz]];
		zz[i]=1;
	}
	//cout<<endl<<sum<<' '<<cur<<endl;
	while(cur>0){
		ll t=-1;
		if(zz[0]<=m){
			t=0;
		}
		for(int i=1;i<=sz;i++){
			ll ii=p[i];
			//cout<<i<<'*'<<a[ii][zz[i]].w<<' ';
			if(zz[i]<=n){
				if(t==-1)
					t=i;
				else if(t==0&&e[zz[0]].w>a[ii][zz[i]].w)
					t=i;
				else if(a[p[t]][zz[t]].w>a[ii][zz[i]].w)
					t=i;
			}
		}
		if(t==-1){
			return;
		}
		//cout<<endl<<t<<endl;
		ll x,y,w;
		if(t==0){
			x=e[zz[0]].x,y=e[zz[0]].y,w=e[zz[0]].w;
		}
		else{
			x=a[p[t]][zz[t]].x,y=a[p[t]][zz[t]].y,w=a[p[t]][zz[t]].w;
		}
		ll fx=find(x),fy=find(y);
		if(fx==fy){
			zz[t]++;
			continue;
		}
		//cout<<x<<' '<<y<<' '<<w<<endl;
		f[fx]=fy;
		sum+=w;
		zz[t]++;
		cur--;
	}
	//cout<<sum;
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	bool isA=1;
	ans=1e18;
	for(int i=1;i<=m;i++){
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		e[i]={x,y,z};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]){
			isA=0;
		}bool fl=0;
		for(int j=1;j<=n;j++){
			ll x;
			scanf("%lld",&x);
			if(!x){
				fl=1;
			}
			a[i][j]={n+i,j,x};
		}
		sort(a[i]+1,a[i]+n+1,cmp);
		isA&=fl;
	}
	for(int j=1;j<=n+k;j++){
		f[j]=j;
	}
	if(k==0)
		Kruskal();
	else if(isA){
		for(int i=1;i<=k;i++){
			int tt=0;
			for(int j=1;j<=n;j++){
				if(!a[i][j].w){
					tt=a[i][j].y;break;
				}
			}
			for(int j=1;j<=n;j++){
				if(a[i][j].y!=tt){
					e[++m]={tt,a[i][j].y,a[i][j].w};
				}
			}
		}
		sort(e+1,e+m+1,cmp);
		Kruskal();
	}
	else{
		//cout<<"NY";
		for(int i=0;i<(1<<k);i++){
			sz=0;
			for(int j=1;j<=k;j++){
				if(i&(1<<(j-1))){
					p[++sz]=j;
				}
			}
			//for(int j=1;j<=sz;j++){
			//	cout<<p[j]<<' ';
			//}
			Kruskal();
			//cout<<endl<<ans<<endl;
			for(int j=1;j<=n+k;j++){
				f[j]=j;
			}
		}
	}
	cout<<ans;
	return 0;
}
