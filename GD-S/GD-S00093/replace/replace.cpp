#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,t=1;
	char a;
	while(!isdigit(a=getchar()))t=a=='-'?-1:t;
	do{x=(x<<3)+(x<<1)+(a^48);}while(isdigit(a=getchar()));
	return x*t;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline unsigned ll qpow(unsigned ll x,ll m){
	unsigned ll ans=1;
	for(;m;m>>=1,x=x*x)m&1?ans=ans*x:0;
	return ans;
}
const int N=2e5+5,base=19260817;
int n,m,l[N];
ll ans;
unsigned ll v1[N],v2[N],pre[N*20],fac[N*20];
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		l[i]=s1[i].length();
		for(int j=0;j<l[i];j++)
			v1[i]=base*v1[i]+s1[i][j],v2[i]=base*v2[i]+s2[i][j];
		//cout << v1[i] << ' ' << v2[i] << '\n';
	}
	fac[0]=1;
	for(int i=1;i<4e6;i++)fac[i]=fac[i-1]*base;
	while(m--){
		cin >> t1 >> t2;
		unsigned ll tmp=0;
		int len=t1.length();
		pre[0]=t1[0],tmp=t2[0];ans=0;
		for(int i=1;i<len;i++)pre[i]=pre[i-1]*base+t1[i],tmp=tmp*base+t2[i];
		for(int i=1;i<=n;i++){
			if(pre[l[i]-1]==v1[i])ans+=(pre[len-1]-v1[i]+v2[i]==tmp);
			for(int j=1;j+l[i]-1<len;j++){
				//cout << j << ' ' << j+l[i]-1 << '\n';
				if(pre[j+l[i]-1]-pre[j-1]*fac[l[i]]==v1[i])
					ans+=(pre[len-1]-v1[i]*fac[j]+v2[i]*fac[j]==tmp);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
