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
const int maxn = 1e5+5;
i64 n,a[maxn][3],pt[maxn];
IV solve(){
	n=read();
	i64 sum=0;
	F(i,1,n){
		pt[i]=0;
		F(j,0,2)a[i][j]=read();
		F(j,1,2)if(a[i][pt[i]]<a[i][j])
			pt[i]=j;
		sum+=a[i][pt[i]];
	}
	i64 cnt[3]={0,0,0};
	F(i,1,n)cnt[pt[i]]++;
	i64 mx=max({cnt[0],cnt[1],cnt[2]});
	if(mx<=n/2){
		printf("%lld\n",sum);
		return;
	}
	i64 pos=0;
	F(i,0,2)if(mx==cnt[i])
		pos=i;
	i64 nd=cnt[pos]-n/2;
	vector<i64>V;

	F(i,1,n)if(pt[i]==pos){
		i64 mn=1e18;
		F(j,0,2)if(j!=pos)
			mn=min(mn,a[i][pos]-a[i][j]);
		// cout<<mn<<endl;
		V.push_back(mn);
	}
	sort(V.begin(),V.end());
	F(i,0,nd-1)
		sum-=V[i];
	printf("%lld\n",sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	i64 T=read();while(T--)solve();return 0;
}