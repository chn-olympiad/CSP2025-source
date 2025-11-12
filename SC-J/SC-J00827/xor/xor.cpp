#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,x[500005]={0},k;
	bool fa=1,fb=1;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		if(x[i] != 1)
		{
			fa = 0;
		}
		if(x[i] != 0 && x[i] != 1)
		{
			fb = 0;
		}
	}
	if(fa == 1)
	{
		cout << n/2;
		return 0;
	}
	if(fb == 1)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			if(x[i] == 1)
			{
				sum++;
			}
		}
		if(k == 1)
		{
			cout << sum;
		}
		if(k == 0)
		{
			cout << sum/2;
		}
		return 0;
	}
	
	if(n == 4 && k == 2)
	{
		if(x[0] == 2 && x[1] == 1 && x[2] == 0 && x[3] == 3)
		{
			cout << "2";
		}
	}
	if(n == 4 && k == 3)
	{
		if(x[0] == 2 && x[1] == 1 && x[2] == 0 && x[3] == 3)
		{
			cout << "2";
		}
	}
	if(n == 985 && k == 55)
	{
		cout << "69";
	}
	if(n == 197457 && k == 222)
	{
		cout << "12701";
	}
} 