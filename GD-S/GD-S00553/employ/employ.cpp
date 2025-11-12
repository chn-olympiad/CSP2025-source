#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define pi pair<int,int>
#define eb emplace_back
#define vi vector<int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=503,mo=998244353;
int n,m,c[N],cnt[N],sum,f[N][N],g[N][N],ans;
ll jc[N];
char s[N];
void add(int &x,int y){x+=y;if(x>=mo)x-=mo;}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=1;fo(i,1,n) jc[i]=jc[i-1]*i%mo;
	scanf("%s",s+1);
	fo(i,1,n) scanf("%d",&c[i]),cnt[c[i]]++;
	fo(i,1,n) cnt[i]+=cnt[i-1];
	f[0][0]=1;
	fo(i,1,n)
	{
		if(s[i]=='0'){sum++;continue;}
		fo(j,0,i)
		{
			fo(k,0,i) if(f[j][k])
			{
				add(g[j][k],f[j][k]);
				add(g[j][k+1],1ll*(mo-f[j][k])*(cnt[sum+j]-k)%mo);
				add(g[j+1][k+1],1ll*f[j][k]*(cnt[sum+j]-k)%mo);
			}
		}
		fo(j,0,i) fo(k,0,i) f[j][k]=g[j][k],g[j][k]=0;
	}
	fo(j,0,n) fo(k,0,n) if(j+sum<=n-m) ans=(ans+f[j][k]*jc[n-k])%mo;
	printf("%d",ans);
}
