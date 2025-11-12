#include<bits/stdc++.h>
#define gc() getchar()
#define r(x) (x)=read()
#define rs(x) (x)=reads()
#define ll long long
using namespace std;
const ll N=505,JN=3628805,M=998244353;
inline ll read(){
	ll x=0,f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=gc();}
	return x*f;
}
inline string reads(){
	char c=gc();
	string s="";
	while(c==' '||c=='\n'||c=='\r'||c=='\t')c=gc();
	while(!(c==' '||c=='\n'||c=='\r'||c=='\t')){s+=c;c=gc();}
	return s;
}
inline void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline ll jchn(ll x){
	ll ans=1;
	for(ll i=2;i<=x;i++)ans=(ans*i)%M;
	return ans;
}
ll n,m,c[N];
string s;
inline void solve(){
	r(n),r(m);
	rs(s);
	ll nms=0,plss=0;
	for(ll i=0;i<n;i++){
		if(s[i]=='1')nms++;
	}
	if(nms==n||(n==m&&nms)){
		putchar('0');
		return;
	}
	if(!nms){
		write(jchn(n));
		return;
	}
	for(ll i=1;i<=n;i++){
		r(c[i]);
		if(c[i]==0)plss++;
	}
	write(((n-nms)*jchn(n-1))%M);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll t=1;
	while(t--)solve();
	return 0;
}

