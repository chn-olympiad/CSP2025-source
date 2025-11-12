#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
constexpr int MOD=998244353;

int n;
array<int,N> a;
int num,cnt;

int ans;

void dfs(int x,int sum)
{
	if(x==cnt)
	{
		if(sum>num)
		{
			ans++;
			ans%=MOD;
		}
		return;
	}
	
	dfs(x+1,sum+a.at(x) );
	dfs(x+1,sum);
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a.at(i) );
	sort(a.begin()+1,a.begin()+1+n);
	
	// if(false)
	// {
	// 	for(int k=n;k>=1;k--)
	// 	for(int i=1;i<=k-2;i++)
	// 	for(int j=1;j<=i;j++)
	// 	ans+=j,ans%=MOD;
		
	// 	ans++;
	// 	cout<<ans<<endl;
	// 	return 0;
	// 	//NO!
	// }
	
	for(int i=3;i<=n;i++)
	{
		cnt=i;
		num=a.at(i)<<1;
		dfs(1,a.at(i));
	}
	
	cout<<ans%MOD<<endl;
    return 0;
}
