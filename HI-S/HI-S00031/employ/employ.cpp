#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];

int main()
{
	freopen(".in","r",stdin);
	freopen(".in","w",stdout);
	int g[10000];
	int c;
	cin >> n >> m;
	int b;
	cin >> b;
	for(int i = 1;i <= n;i++)
	{
		cin >> g[i];
	}
	if(m = n)
	{
		cout << "0";
	
	}
	else
	{
		cout << n;
	}
	
	return 0;
}
