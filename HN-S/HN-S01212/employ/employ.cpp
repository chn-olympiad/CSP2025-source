#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n,m;
int a[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(s.find('0') != -1)
	{
		cout<<0;
		return 0;
	}
	else if(a[1] == 0)	cout<<0;
	else
	{
		int ans = 1;
		for(int i=1;i<=n;i++)
		{
			ans = ans*i%998244353;
		}
		cout<<ans;
	}
	return 0;
}
