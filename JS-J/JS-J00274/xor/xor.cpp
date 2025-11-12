#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int arr[n + 2];
	bool a = 1;
	for(int i = 1;i <= n;i++)
	{
		cin>>arr[i];
		if(arr[i] != 1) a = 0;
	}
	if(a == 1 && k == 0)
	{
		cout<<n / 2;
		return 0;
	}
	else if(k == 1)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(arr[i] == 1) ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(k == 0)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(arr[i] == 0) ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
