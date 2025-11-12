#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int a[N];

int addtwo(int x,int y)
{
	int t[30] = {};
	int r = 1;
	long long cnt = 0;
	if(x > y)
	{
		swap(x,y);
	}
	while(y != 0)
	{
		int p = 0;
		if(x != 0)
		{
			p = x%10;
		}
		int q = y%10;
		if(p != q)
		{
			t[r] = 1;
		}
		else
		{
			t[r] = 0;
		}
		x /= 10;
		y /= 10;
		r++;
	}
	for(int i = r;i >= 1;i--)
	{
		cnt += t[i]*r;
	}
	return cnt;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long ans = 0;
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	int si = 1;
	for(int i = 1;i <= n;i++)
	{
		long long cnttwo = a[i];
		if(cnttwo == k)
		{
			ans++;
			si = i+1;
		}
		if(cnttwo < k)
		{
			cnttwo = addtwo(cnttwo,a[i+1]);
		}
		if(cnttwo > k)
		{
			cnttwo = 0;
			i = si+1;
		}
	}
	
	cout << ans;
	
	return 0;
}
