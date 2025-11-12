#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m,k,f[2*N],ans,c[N],z[15][N];
struct node{
	ll u,v,w;
}a[2*N],b[2*N];
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
ll findl(ll x){
	if(f[x]==x) return x;
	f[x]=findl(f[x]);
	return f[x];
}
void solve1(){
	for(ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=n;i++){
		f[i]=i;
	}
	for(ll i=1;i<=m;i++){
		ll dx=findl(a[i].u);
		ll dy=findl(a[i].v);
		if(dx!=dy){
			f[dy]=dx;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return;
}
void solve2(){

	ll ai=m;
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++){
			ai++;
			a[ai].u=n+i;
			a[ai].v=j;
			a[ai].w=z[i][j];
		}
	}
	for(ll i=1;i<=ai;i++){
		f[i]=i;
	}	
	sort(a+1,a+ai+1,cmp);
	for(ll i=1;i<=ai;i++){
		ll dx=findl(a[i].u);
		ll dy=findl(a[i].v);
		if(dx!=dy){
			f[dy]=dx;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return;
}
void solve3(){
	ll xans=0;
	ll ai=m;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=n;i++){
		f[i]=i;
	}
	for(ll i=1;i<=m;i++){
		ll dx=findl(a[i].u);
		ll dy=findl(a[i].v);
		if(dx!=dy){
			f[dy]=dx;
			xans+=a[i].w;
		}
	}
	ll yans=0;
	for(ll x=1;x<=k;x++){
		yans=c[x];
		ll minn=0x3f3f3f3f,mini;
		for(ll j=1;j<=n;j++){
			if(z[x][j]<minn){
				minn=z[x][j];
				mini=j;
			}
		}
		ll bi=m;
		for(ll i=1;i<=m;i++){
			b[i].u=a[i].u;
			b[i].v=a[i].v;
			b[i].w=a[i].w;
		}
		for(ll i=1;i<=n;i++){
			bi++;
			b[bi].u=n+x;
			b[bi].v=i;
			if(i==mini){
				b[bi].w=0;
			}else{
				b[bi].w=z[x][i];
			}
		}
		for(ll i=1;i<=bi;i++){
			f[i]=i;
		}
		sort(b+1,b+bi+1,cmp);
		for(ll i=1;i<=bi;i++){
			ll dx=findl(b[i].u);
			ll dy=findl(b[i].v);
			if(dx!=dy){
				f[dy]=dx;
				yans+=b[i].w;
			}
		}
		if(yans<xans){
			ans+=c[x]+minn;
			for(ll i=1;i<=n;i++){
				ai++;
				a[ai].u=n+x;
				a[ai].v=i;
				if(i==mini){
					a[ai].w=0;
				}else{
					a[ai].w=z[x][i];
				}
			}
		}
	}
	for(ll i=1;i<=ai;i++){
		f[i]=i;
	}	
	sort(a+1,a+ai+1,cmp);
	for(ll i=1;i<=ai;i++){
		ll dx=findl(a[i].u);
		ll dy=findl(a[i].v);
		if(dx!=dy){
			f[dy]=dx;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return;
}
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	if(k==0){
		solve1();
		return 0;
	}
	for(ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	ll cnt=0;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			cnt=1;
		}
		for(ll j=1;j<=n;j++){
			cin>>z[i][j];
		}		
	}
	if(cnt==0){
		solve2();
		return 0;
	}
	solve3();
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
