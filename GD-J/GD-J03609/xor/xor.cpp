#include <iostream>
using namespace std;
int n,k,ans,a[500005],sa[500005];
void db()
{
	int cnt = 0;
	if(k == 1)
	{
		for(int i = 1;i <= n;i++)
			cnt += a[i];
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 0) cnt++;
			else if(a[i + 1] == 1)
			{
				cnt++;i++;
			}
		}
	}
	cout << cnt << endl;
	return;
}
void dfs(int l,int s)
{
	if(l > n)
	{
		ans = max(ans,s);
		return;
	}
	for(int i = l;i <= n;i++)
	{
		ans = max(ans,s);
		if((sa[i] ^ sa[l - 1]) == k)
		{
			dfs(i + 1,s + 1);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool fa = (k == 0),fb = (k <= 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1) fa = false;
		if(a[i] > 1) fb = false;
		sa[i] = sa[i - 1] ^ a[i];
	}
	if(fa) cout << n / 2 << endl;
	else if(fb) db();
	else
	{
		for(int i = 1;i <= n;i++)
			dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}
//45
