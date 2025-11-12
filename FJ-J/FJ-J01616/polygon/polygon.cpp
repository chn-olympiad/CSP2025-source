#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int arr[5005],qt[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>arr[i];
		qt[i] = qt[i-1]+arr[i];
	}
	int ans=0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
		 	if(qt[i] - qt[j] == 5)
		 	{
		 		ans++;
			 }
		} 
	}
	cout<<ans;
	return 0;
}
