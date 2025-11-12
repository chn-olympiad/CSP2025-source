#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define her1 20081214
#define IV void
#define cht 998244353
#define ull unsigned long long
#define mem(x,val) memset(x,val,sizeof x)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
using i64 = long long;
const int maxn = 5e2+5;
IV cadd(i64&x,i64 val){x=(x+val)%cht;}
char s[maxn];
i64 dp[maxn][maxn],nw[maxn][maxn],tmp[maxn][maxn],C[maxn][maxn];
i64 n,m,c[maxn],p[maxn],pre[maxn],suf[maxn],cnt[maxn],fac[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();scanf("%s",s+1);

	F(i,1,n)c[i]=read();F(i,1,n)p[i]=i;
	fac[0]=1;F(i,1,n)fac[i]=fac[i-1]*i%cht;
	F(i,1,n)pre[c[i]]++,suf[c[i]]++,cnt[c[i]]++;
	F(i,1,n)pre[i]+=pre[i-1];
	D(i,n,0)suf[i]+=suf[i+1];
	F(i,0,n){
		C[i][0]=1;
		F(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%cht;
	}
	//cnt >cnt 
	dp[0][0]=1;
	F(i,1,n){
		if(s[i]=='1'){
			mem(nw,0);mem(tmp,0);
			F(c,0,i){
				i64 t=pre[c];
				F(val,0,i){
					i64 r0=t-((i-1)-val),r1=suf[c+1]-val;
					cadd(nw[c][val+1],dp[c][val]);
					cadd(tmp[c+1][val],dp[c][val]*r0);
				}
			}
			F(c,0,i)F(val,0,i){
				i64 mul=1;
				F(p,0,cnt[c])if(val>=p){
					cadd(nw[c][val-p],tmp[c][val]*C[cnt[c]][p]%cht*mul);
					mul=mul*(val-p)%cht;
				}
			}
			F(c,0,i)F(val,0,i)
				dp[c][val]=nw[c][val];
		}
		else{
			mem(nw,0);mem(tmp,0);
			F(c,0,i){
				i64 t=pre[c];
				F(val,0,i){
					i64 r0=t-((i-1)-val),r1=suf[c+1]-val;
					cadd(tmp[c+1][val+1],dp[c][val]);
					cadd(tmp[c+1][val],dp[c][val]*r0);
				}
			}
			F(c,0,i)F(val,0,i){
				i64 mul=1;
				F(p,0,cnt[c])if(val>=p){
					cadd(nw[c][val-p],tmp[c][val]*C[cnt[c]][p]%cht*mul);
					mul=mul*(val-p)%cht;
				}
			}
			F(c,0,i)F(val,0,i)
				dp[c][val]=nw[c][val];
		}
	}

	i64 Ans=0;
	// cout<<suf[0]<<endl;
	F(c,0,n-m)
		cadd(Ans,dp[c][suf[c+1]]*fac[suf[c+1]]);
	cout<<(Ans+cht)%cht;
	return 0;
}