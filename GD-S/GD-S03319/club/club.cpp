#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bll __int128
#define vii vector<int>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define sec second
#define Qii queue<int>
#define vll vector<ll>
#define vpi vector<pii>
#define ci const int
using namespace std;
const int N=1e5+5;
int a[N][5];
int s[5];
vii inc[5];
int T,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		s[1]=s[2]=s[3]=0;
		inc[1].clear(),inc[2].clear(),inc[3].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int Max=-1,num=0;
			for(int j=1;j<=3;j++)if(Max<a[i][j])Max=a[i][j],num=j;
			s[num]++,ans+=Max;
			int mmax=-1;
			for(int j=1;j<=3;j++)if(j!=num)mmax=max(mmax,a[i][j]);
			inc[num].pb(Max-mmax);
		}
		for(int i=1;i<=3;i++)
		{
			if(s[i]>=n/2)
			{
				sort(inc[i].begin(),inc[i].end());
				for(int j=0;j<s[i]-n/2;j++)ans-=inc[i][j];
			}
		}
		printf("%lld\n",ans);
	}
}
