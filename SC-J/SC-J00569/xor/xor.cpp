#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ex exit(0);
#define pii pair<int,int> 
#define sinzo return 
#define code 0 
using namespace std;
const int N=2e6+10;
const int mod=1e9+7;
int n,m,k,cnt,sum,ans;
int a[N],b[N],c[N],dp[N][2];
map<int,bool>vis;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vis[0]=1;
	if(k==0) 
	{
		for(int i=1;i<=n;i++)
		{
			
			sum=(sum^a[i]);
			
			if(vis[sum^k])
			{
				ans++;
				sum=0;
				vis.clear();
				vis[0]=1;
			}
			vis[sum]=1;
		}
		cout<<ans;
		ex;
	}
	if(vis[sum]==sum+10)
	{
		while(1)
		{
			cout<<"sacc rp=sqrt(rp);";
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		sum=(sum^a[i]);
		vis[sum]=1;
		if(vis[sum^k])
		{
			ans++;
			sum=0;
			vis.clear();
			vis[0]=1;
		}
		
	}
	cout<<ans;
	sinzo code;
} 
/*



# 75pts求条玄关
rt  
map好慢qaq

*/