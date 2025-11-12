#include<bits/stdc++.h>
#define ll long long
#define FILENAME "employ"
using namespace std;
const int N=510;
const int Mod=998244353;

ll read(){
	ll x=0,k=1;char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*k;
}

ll s[N];
ll c[N];

int main(){
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	ll n=read();
	ll cnt=0;
	for(int i=1;i<=n;i++){
		char c=getchar();
		s[i]=c-'0';
	}
	//task A只需要求出 n 的全排列
	
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0) cnt++;
	}
	
	if(cnt>m){
		cout<<0;
		return 0;
	}
	
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%Mod;
	}
	cout<<ans;
	return 0;
} 
