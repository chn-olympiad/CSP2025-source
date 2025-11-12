#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int arr[1000100];
string ans; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size() - 1;
	for(int i = 0;i <= len;i ++)
	{
		arr[i] = -1; 
	}
	for(int i = 0;i <= len;i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			arr[i] = s[i] - '0';
		}
	}
	sort(&arr[0] , &arr[len + 1]);
	for(int i = len;i >= 0;i --)
	{
		if(arr[i] != -1)
		{
			ans += arr[i] + '0';
		}
	}
	cout<<ans;
	return 0;
}
