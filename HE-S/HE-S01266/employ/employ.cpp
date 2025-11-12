#include<bits/stdc++.h>
#define ll long long 
using namespace std;


const ll N=500+100;
const ll MOD=998244353;
ll n,m,ans;
ll a[N],c[N];
bool f[N];
string s;


bool pd(){
	ll ret=0,res=0;
	for(ll i=1;i<=n;i++){
		if(s[i-1]=='1'&&c[a[i]]>ret){
			res++;
		}
		else{
			ret++;
		}
		if(res>=m){
			return true;
		}
		if(n-ret<m){
			return false;
		}
	}
	return false;
}


void qpl(ll x){
	if(x==n+1){
		if(pd()==true){
			ans=(ans+1)%MOD;
		}
		return;
	}
	
	for(ll i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			a[x]=i;
			qpl(x+1);
			f[i]=false;
		}
	}
	return;
}


signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	
	
	qpl(1);
	
	
	printf("%lld\n",ans);
	
	
	return 0;
}
