#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],f[5001],cnt,sum,ans;
bool book[5001];
long long jiecheng(int n)
{
	long long ans = 1;
	for(int i = 2;i <= n;i++)
	{
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}
void dfs(int nows,int shu,int maxx)
{

	if(shu >= 3 && ans > maxx*2)
	{
		sum++;
		sum %= 998244353;
	/*	for(int i = 1;i <= cnt;i++)
		{
			cout << f[i] <<  " "; 
		}
		cout << endl;*/
	}
	for(int i = nows;i <= n;i++)
	{
		if(book[i] == 0)
		{
			book[i] = 1;
			f[++cnt] = a[i];
			ans += a[i];
			dfs(i+1,shu+1,a[i]);
			book[i] = 0;
			ans -= a[i];
			f[cnt] = 0;
			cnt--;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n <= 20)
	{
		dfs(1,0,0);
		cout << sum;
	}
	else
	{
		long long sum = 0;
		for(int i = 3;i <= n;i++)
		{
				sum +=  jiecheng(n)/(jiecheng(i) * jiecheng(n-i));
				sum %= 998244353;
		}	
		cout << sum;
	}
	return 0;
}