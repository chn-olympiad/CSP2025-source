#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define ll int
#define ri register int
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline ll read(){
	ll r=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<1)+(r<<3)+(c^48);
		c=getchar();
	}
	return r*f;
}
inline ll Min(ll a,ll b){
	return a<b?a:b;
}
inline ll Max(ll a,ll b){
	return a>b?a:b;
}
const int N=2e5+5;
int n,m,c[N],ans=1;
string s;
const ll mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();cin>>s;
	for(int i=1;i<=m;i++) c[i]=read();
	for(int i=1;i<=m;i++){
		ans*=n;
		ans%=mod;
	}
	write(n%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
