#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		x=(f?-x:x);return x;
	}template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		char tmp[41];int cnt=0;
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
};
using namespace FastIO;
const int N=5e2+10,M=18,MOD=998244353;
int f[1<<M][M],c[N],n,m;
char s[N];
int pop_count(int x){int res=0;while(x) res+=(x&1),x>>=1;return res;}
inline void pls(int&a,int b){a+=b;if(a>=MOD) a-=MOD;}
ll qpow(ll a,ll b){ll res=1;while(b){if(b&1) res=res*a%MOD;a=a*a%MOD,b>>=1;}return res;}
void solve1(){
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int now=pop_count(i);
		for(int j=0;j<n;j++){
			if(!(i&(1<<j))) continue;
			for(int k=0;k<now;k++){
				if(s[now]=='0'||k>=c[j+1]) pls(f[i][k+1],f[i^(1<<j)][k]);
				else pls(f[i][k],f[i^(1<<j)][k]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) pls(ans,f[(1<<n)-1][i]);
	write(ans,'\n');
}
void solve2(){
	int sum=0,fac=1;
	for(int i=1;i<=n;i++){
		fac=1ll*fac*i%MOD;
		if(c[i]) sum++;
	}
	if(sum>=m) write(fac,'\n');
	else printf("0\n");
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m),scanf("%s",s+1);
	for(int i=1;i<=n;i++) read(c[i]);
	bool A=true;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){A=false;break;}
	}
	if(n<=18) solve1();
	else if(A) solve2();
	fclose(stdin);fclose(stdout);
	return 0;
}
