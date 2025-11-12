#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'//交互题注释
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
inline ll read(){
	ll x=0,t=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-t;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return t*x;
}
const int mod=998244353;
int n,a[500005],ans;
bool check(int nw){
	int s=0,mx=0,i=n;
	while(nw){
		if(nw&1){
			s+=a[i];
			mx=max(mx,a[i]);
		}
		nw>>=1,i--;
	}
	return (s>2*mx);
}
ll C(int n,int m){//n里选m 
	ll s=1;
	for(int i=m+1;i<=n;i++){
		s=(s*i)%mod;
	}
	return s;
}
bool ts;
signed main(){
	file("polygon");
	cin>>n;
	ts=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1)ts=0;
	}
	if(ts){
		for(int i=3;i<=n;i++){
			int l=C(n,i);
//			cerr<<i<<' '<<l<<endl;
			ans=(ans+l)%mod;
		}
	}else{
		for(int i=7;i<=(1ll<<n)-1;i++){
			if(check(i)){
				ans=(ans+1)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5
1 1 1 1 1

123
124
125
134
135
145
234
235
245
345
1234
1235
1245
1345
2345
12345

1~n里选(3~n)个(组合) 
*/
