#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace fastIO{
	int read()
	{
		char c;
		int sum=0,res=1;
		c=getchar();
		while(c>'9'||c<'0')
		{
			if(c=='-')res=-1;
			c=getchar();
		}
		while(c<='9'&&c>='0')
		{
			sum=(c-'0')+sum*10;
			c=getchar();
		}
		return sum*res;
	}
	void out(int sum)
	{
		if(sum<0)
		{
			putchar('-');
			sum=-sum;
		}
		if(sum<10)
		{
			putchar(sum+'0');
		}
		else
		{
			out(sum/10);
			putchar(sum%10+'0');
		}
	}
	void wenjian()
	{
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
	}
};
int n,a[1008617],ans;
const int MOD=998244353;
void dfs(int now,int maxn,int res,int use)
{
	if(clock()>965)return;
	if(now>n)
	{
		if(use>=3&&2*maxn<res)
		{
			ans++;
//		    cout<<now<<" "<<maxn<<" "<<res<<" "<<use<<'\n';
		}
		if(ans>MOD)ans-=MOD;
		return;
	}
	dfs(now+1,maxn,res,use);
	dfs(now+1,max(maxn,a[now]),res+a[now],use+1);
}
int qpow(int a,int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)ans=ans*a%MOD;
	return ans;
 } 
signed main()
{
	fastIO::wenjian();
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=fastIO::read();
    bool all0=true;
    for(int i=1;i<=n;i++)if(a[i]!=0)all0=false;
    if(all0)
    {
    	cout<<(MOD+qpow(2,n)-1-n-(n*(n-1)/2)%MOD)%MOD;
	}
	else
	{
        dfs(1,0,0,0);
        cout<<ans;
    }
	return 0;
}
// 64 pts at 10:30