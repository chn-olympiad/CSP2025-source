#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	while(cin>>a)
	{
		if(a>='0'&&a<='9')
		{
			ans[a-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(ans[i])
		{
			for(ll j=1;j<=ans[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
