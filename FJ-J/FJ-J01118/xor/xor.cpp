#include <bits/stdc++.h>
using namespace std;

int a[500005];

struct Yhuo
{
	int begin , end;
}h[500005];

string shzer(int x)
{
	int t = x;
	string y = "";
	string ans = "";
	while(t > 0)
	{
		if(t % 2 == 0)
		{
			y += '0';
		}
		else
		{
			y += '1';
		}
	}
	for(int i = y.size() - 1; i >= 0; i--)
	{
		ans += y[i];
	}
	return ans;
 } 
 
 int erzsh(string s)
 {
 	int mul = 1;
 	int ans = 0;
 	for(int i = s.size() - 1; i >= 0; i--)
 	{
 		if(i != s.size() - 1)
 		{
 			mul *= 2;
		}
		ans = ans * 10 + mul * (s[i] - '0');
	}
	return ans;
 }
 
 string yh(string x , string y)
 {
 	int size0 = max(x.size() , y.size());
 	string ans = "";
 	for(int i = 0; i < size0; i++)
 	{
 		if(i < min(x.size() , y.size()))
 		{
 			if(x[i] == y[i])
 			{
 				ans += '0';
			}
			else
			{
				ans += '1';
			}
		}
		else
		{
			if(i >= x.size())
			{
				ans += y[i];
			}
			else
			{
				ans += x[i];
			}
		}
	}
	return ans;
} 

bool cmp(Yhuo x , Yhuo y)
{
	return x.end < y.end;
}

int main()
{
	freopen(xor.in , "r" , stdin);
	freopen(xor.out , "w" , stdout); 
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int x = 1; x <= n; x++)
	{
		for(int y = x; y <= n; y++)
		{
			string num = shzer(a[x]);
			for(int j = x + 1; j <= y; j++)
			{
				num = yh(num , shzer(a[j]));
			}
			int num2 = erzsh(num);
			if(num2 == k) 
			{
				cnt++;
				h[cnt].begin = x;
				h[cnt].end = y;
			}
		}
	}
	int ans = 1;
	sort(h + 1 , h + cnt + 1 , cmp);
	int r = h[1].end;
	for(int i = 2; i <= cnt; i++)
	{
		if(h[i].begin > r)
		{
			r = h[i].end;
			ans++;
		}
	}
	cout << ans;
	return 0;
 } 
