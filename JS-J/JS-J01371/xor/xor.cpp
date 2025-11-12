#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[500010];
vector<int> qj1;
vector<int> qj2;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		arr[i]=arr[i-1]^arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((arr[j]^arr[i-1])==k)
			{
				//cout<<i<<' '<<j<<endl;
				qj1.push_back(i);
				qj2.push_back(j);
				break;
			}
		}
	}
	int m=qj1.size();
	vector<int> dp(m+10,0);
	for(int i=m-1;i>=0;i--)
	{
		int j=i+1;
		for(j=i+1;qj1[j]<=qj2[i];j++)
		{
			if(j>n)
				break;
		}
		dp[i]=max(dp[i+1],dp[j]+1);
	}
	//for(int i=0;i<m;i++)
	//{
	//	cout<<dp[i]<<' '<<qj1[i]<<' '<<qj2[i]<<endl;
	//}
	cout<<dp[0];
	return 0;
}
