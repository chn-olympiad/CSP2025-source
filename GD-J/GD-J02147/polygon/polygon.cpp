#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5010];
int ans;
vector<int> ty;
void dfs(int k,int ma,int sum,int tal)
{
//	cerr<<k<<' '<<ma<<' '<<sum<<' '<<tal<<endl;
	if(k>n)
	{
		if(tal>=3&&sum>ma*2)
		{
			ans++;
			/*for(auto v:ty)
			{
				cerr<<v<<' ';
			}
			cerr<<endl;*/
//			cerr<<ma<<' '<<sum<<endl;
		}
		return;
	}
	dfs(k+1,ma,sum,tal);
	if(a[k]>ma)
	{
		ma=a[k];
	}
	ty.push_back(k);
	dfs(k+1,ma,sum+a[k],tal+1);
	ty.pop_back();
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i];
	bool f=true;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]>1)
		{
			f=false;
			break;
		}
	}
	if(f)
	{
		long long ans=0;
		for(long long i=3; i<=n; ++i)
		{
			long long sum=1;
			long long t=n-i;
			for(long long j=i+1; j<=n; ++j)
			{
				sum*=j;
				if(sum>mod)
				{
					for(;t>=2; --t)
					{
						if(sum%t==0) sum/=t;
					}
				}
			}
			for(;t>=2;--t)
			{
				sum/=t;
			}
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

