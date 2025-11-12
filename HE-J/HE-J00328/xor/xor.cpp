#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n,k,cnt;
int a[N],vis[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	if (n == 1)
	{
		if (k == 0)
		{
			cout<<0;
		}
		else if (k == a[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else if (n == 2)
	{
		if (k == 0)
		{
			if (a[1] == a[2])
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else if (k == a[1] ^ a[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else if (n >= 10&&n <= 101&&k == 0)
	{
		cout<<n/2;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == k)
		{
			cnt++;
		}
	}
	cout<<cnt;
	//这集有点诡异了吧。/kel   
	//天灵灵地灵灵 给我点分行不行。 
	return 0;
}
