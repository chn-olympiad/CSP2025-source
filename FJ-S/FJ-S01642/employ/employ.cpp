#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505,mod=998244353;

ll n,m,c[N],fac[N];
string s;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void teA(){
	ll tot=n;
	for(ll i=1;i<=n;++i){
		c[i]=read();
		if(c[i]==0)--tot;
	}
	fac[0]=1;
	for(ll i=1;i<=tot;++i)fac[i]=fac[i-1]*i%mod;

}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	n=read(),m=read();
	cin>>s;
	bool f1=true;
	for(ll i=0;i<s.size();++i)if(s[i]!='1')f1=false;
	teA();
	return 0;
}

