#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+8;
int n,k;
int a[N],mx[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int dp=0;
		int val=a[i]^a[i];
		for(int j=i;j>=1;j--)
		{
			val=val^a[j];
		//	cout<<val<<" ";
			if(val==k)
			{
				dp=mx[j-1]+1;
				break;//炒鸡优化！！！把大样例卡过了！！！
			}
		}
		//cout<<'\n';
		mx[i]=max(mx[i-1],dp);
	}
	cout<<mx[n];
	return 0;
}
/*

4
*/