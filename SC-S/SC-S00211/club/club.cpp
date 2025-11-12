#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],b[N],c[N];
struct del{
	int ifx,delta;
}d[N]; int cntx,cnty,mov;
bool cmp(del x,del y){
	return x.delta>y.delta;
}
bool jge(int i){//可以继续则1 
	if(d[i].ifx==0) ++mov;
	if(d[i].ifx==1) ++cntx;
	if(d[i].ifx==2) ++cnty;
	
	if(i<=(n/2)) return 1;
	if(cntx>(n-i) or cnty>(n-i)) return 0;
	if(cntx+mov>(n-i) and cnty+mov>(n-i)) return 0;
	return d[i].delta>0;
}
ll solve(int *fst,int *x,int *y){
	ll res=0;
	for(int i=1;i<=n;++i){
		d[i].delta=max(x[i]-fst[i],y[i]-fst[i]);
		if(x[i]==y[i]) d[i].ifx=0;
		if(x[i]>y[i]) d[i].ifx=1;
		if(x[i]<y[i]) d[i].ifx=2;
		res+=0ll+fst[i];
	}
	sort(d+1,d+n+1,cmp);
	cntx=0,cnty=0,mov=0;
	for(int i=1;jge(i);++i){
		//try to kick off
		res+=0ll+d[i].delta;
	}
	return res;
}
int main(){
	//多测要清空 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i]; 
		//假定j是最多的，维护之 
		ll ans=max(solve(a,b,c),solve(b,a,c));
		ans=max(ans,solve(c,a,b));
		cout<<ans<<'\n';
	}
	return 0;
} 