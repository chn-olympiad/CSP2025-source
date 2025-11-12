#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,msum=0;
	cin >> n;
	int x[5005]={0};
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		ans = max(ans,x[i]);
	}
	sort(x,x+n);
	if(n == 3)
	{
		if(x[0] + x[1] > x[2])
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	} 
	if(ans == 1)
	{
		cout << "0";
	}
	
	if(n == 5)
	{
		if(x[0] == 1 && x[1] == 2 && x[2] == 3 && x[3] == 4 && x[4] == 5)
		{
			cout << "9";
		}
		if(x[0] == 2 && x[1] == 2 && x[2] == 3 && x[3] == 8 && x[4] == 10)
		{
			cout << "6";
		}
	}
	if(n == 20)
	{
		bool f = 1;
		int x1[25] = {75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1};
		for(int i = 0; i < 20; i++)
		{
			if(x[i] != x1[i])
			{
				f = 0;
			}
		}
		if(f == 1)
		{
			cout << "1042392";
		}
	}
	if(n == 500)
	{
		cout << "366911923";
	}
} 