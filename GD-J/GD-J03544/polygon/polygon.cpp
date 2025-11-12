#include<bits/stdc++.h>
using namespace std;
const int MN=5090;
int n, ans;
int a[MN], s[MN];
int dfs(int l, int pos, int sum, int cnt)
{
	int pans=0;
	if(cnt == l)
	{
		return bool(sum>2*a[pos]);
	}
	for(int npos=pos+1;npos<=n;npos++)
	{
		sum+=a[npos], cnt++;
		pans+=dfs(l, npos, sum, cnt);
		pans%=998244353;
		sum-=a[npos], cnt--;
	}
	return pans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i=3;i<=n;i++)
	{
		ans+=dfs(i, 0, 0, 0);
		ans%=998244353;
	}
	cout << ans;
	return 0;
}
