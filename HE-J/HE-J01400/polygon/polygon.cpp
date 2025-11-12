#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxn=-INT_MAX,sum=0,ans,a[5050550],n;
const int mod=998244353;
void dfs(int x,int k,int da,int ss,int s)
{
	if(s==x)
	{
		if(ss>da*2)
		{
			ans++;
		}
		return ;
	}
	//cout<<x<<" "<<k<<" "<<da<<" "<<sum<<" "<<s<<endl;
	for(int i=1;i<=2;i++)
	{
		if(k<=n)
		{
			if(i==1)
			{
				dfs(x,k+1,max(a[k],da),ss+a[k],s+1);
			}
			else
			{
				dfs(x,k+1,da,ss,s);
			}
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(a[i],maxn);
	}
	if(n<3)
	{
		cout<<0<<endl;
		return 0;
	}
	else if(n==3)
	{
		if(sum>2*maxn)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	else 
	{
		for(int i=3;i<=n;i++)
		{
			dfs(i,1,0,0,0);
		}
		cout<<ans%mod<<endl;
	}
	return 0;
}
