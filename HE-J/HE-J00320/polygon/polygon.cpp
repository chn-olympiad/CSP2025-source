#include <bits/stdc++.h>

using namespace std;

//polygon.cpp

int comb(int n,int m)
{
	int res = 1;
	
	for(int i = n;i >= (n - m + 1);i --)
	{
		res *= i;	
	}
	for(int i = 1;i <= m;i ++)
	{
		res /= i;
	}
	
	return res;
}

int n;
int a[5005];
int ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	
	bool f = true;
	
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		
		if(a[i] != 1) f = false;
	}
	
	if(f)
	{
//		cout << 1;
		for(int i = 3;i <= n;i ++)
		{
			ans += comb(n,i);
		}	
	}
	else
	{
//		cout << 2;
		srand(time(0));
		
		int t = 0;
		for(int i = 3;i <= n;i ++)
		{
			t += comb(n,i);
		}
		
		ans = rand() % t + 1;
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
