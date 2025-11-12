#include<iostream>
#define ll long long
using namespace std;

const int N=2e1+5;
const int p=998244353;

ll n,ans;
int a[N];

inline void getmx(int &a,int b){
	return a=(a>b?a:b),void();
}

inline ll qpow(ll a,int b){
	ll res=1;
	while(b){
		if(b&1)(res*=a)%=p;
		(a*=a)%=p,b>>=1;
	}
	return res;
}

inline ll ny(ll x){
	return qpow(x,p-2);
}

inline ll mul(ll a,ll b){
	return (a*b)%p;
}

ll mem[10000005];

inline ll jc(int x){
	if(mem[x])return mem[x];
	return mem[x]=mul(x,jc(x-1));
}

inline ll C(ll n,ll m){
	return mul(jc(n),ny(mul(jc(n-m),jc(m))));
}

signed main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","r",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;int mx=0;for(int i=1;i<=n;++i)cin>>a[i],getmx(mx,a[i]);
	if(mx==1){
		for(int i=3;i<=n;++i)ans+=C(n,i);
	}else{
		for(int i=7;i<=(1<<n)-1;++i){
			int sum=0,mx=0,cnt=0;
			for(int j=0;j<n;++j)if((i>>j)&1)getmx(mx,a[j+1]),sum+=a[j+1],++cnt;
			if(cnt<3)continue ;
			ans+=(sum>(mx<<1));
		}
	}
	return cout<<ans<<"\n",0;
}