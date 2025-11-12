#include<bits/stdc++.h>
using namespace std;
int arr[5555] , n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++)
	{
		cin>>arr[i];
	}
	if(n == 3)
	{
		if(arr[1] + arr[2] + arr[3] > 2 * max(max(arr[1] , arr[2]) , arr[3]))
		{
			cout<<1 % 998244353;
		}
		else
			cout<<0;
	}
	else
		cout<<0;
	return 0;
}
