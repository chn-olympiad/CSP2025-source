#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+1;
int arr[N],n,cnt=0;
void dfs(int s,int sum,int d)
{
	if(d>=3)//sum>arr[s]*2&&
	{
		//cout<<sum<<' '<<arr[s]<<' '<<d<<'\n';
		cnt++;
		cnt%=998244353;
	}
	for(int i=s+1;i<=n;i++)
	{
		dfs(i,sum+arr[i],d+1);
	}
}
int f[N]={1,3,6,10,15,21,28,36,45};
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=1)flag=false;
	}
	if(flag)
	{
		for(int i=2;i<=n+1;i++)
		{
			f[i]=f[i-1]+i+1;
		}
		int cnt=pow(2,n)-1;
		cout<<(cnt-f[n-1])%998244353;
		return 0;
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)
	{
		dfs(i,arr[i],1);
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
