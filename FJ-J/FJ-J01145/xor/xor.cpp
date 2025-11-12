#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int n,k,maxn;
int check(int x,int y)
{
	int c = -1,e = 0;
	while(x > 0 || y > 0)
	{
		c++;
		int g1 = x % 2;
		int g2 = y % 2;
		if(g1 != g2)
		{
			e += pow(2,c);
		}
		x /= 2;
		y /= 2;
	}
	return e;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	int l = 1,r = 1,s = 0,t = -1;
	while(l <= n)
	{
		if(l > r)
		{
			r = l;
		}
		if(l != r)
		{
			int st = a[l];
			int s1 = l,s2 = r;
			for(int i = l + 1;i <= r;i++)
			{
				st = check(st,a[i]);
			}
			if(st == k)
			{
				if(l > t)
				{
					s++;
					t = r;
				}
				l++;
			}
			else if(st > k)
			{
				l++;
			}
			else
			{
				if(r != n) r++;
				else l++;
			}
		}
		else if(l == r)
		{
			if(a[l] == k)
			{
				if(l > t)
				{
					s++;
					t = r;
				}
				l++;
			}
			else if(a[l] > k)
			{
				l++;
			}
			else
			{
				r++;
			}
		}
	}
	cout << s;
	return 0;
}
