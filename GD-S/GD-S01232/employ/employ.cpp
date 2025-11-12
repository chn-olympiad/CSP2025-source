#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
typedef long long ll;
ll n,m,sumr[N],v[N],num;
char s[N];
long long ans=1,res;
struct nd{
	ll x,y;
	bool operator<(const nd&a)const{
		return y<a.y;
	}
//	bool operator=(const nd&a)const{return x==a.x&&y==a.y;}
}c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)cin>>s[i],sumr[i]=sumr[i-1]+(s[i]^48);
	for(ll i=1;i<=n;++i)v[i]=i-sumr[i];
	for(ll i=1;i<=n;++i)cin>>c[i].x,c[i].y=i;
	sort(c+1,c+1+n),ans=0;
	ll tmp=100;
	do{
		res=0;
//		for(ll i=1;i<=n;++i)cout<<c[i].x<<' ';
//		cout<<endl;
//		for(ll i=1;i<=n;++i)cout<<c[i].y<<' ';
//		cout<<endl;
		for(ll i=1;i<=n;++i){
//			cout<<(i-res)<<' ';
			if(c[i].x>(i-res-1)&&(s[i]^48))++res;
		}
//		cout<<endl;
		if(res>=m)ans=(ans+1)%mod;
//		cout<<res<<endl;
	}while(next_permutation(c+1,c+1+n));
	cout<<ans<<endl;
	
	return 0;
}

