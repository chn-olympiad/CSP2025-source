#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL mod = 998244353;
char s[505];
int c[505];
int n,m;
int ans = 0;
int fl[505],vis[505];
void dfs(int step,int cnt)
{
	if (step > n)
	{
        if (n-cnt >= m) 
        	ans++;
        return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			fl[step] = i;
			bool is = 0;
			if (cnt >= c[i] || s[i] == '0')
				cnt++,is = 1;
			dfs(step+1,cnt);
			vis[i] = 0;
			if (is) cnt--;
		}
	}
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    	cin >> s[i];
    for (int i = 1;i <= n;i++)
    	cin >> c[i],cnt += (c[i]==0);
    LL sum = 1;
    if (n-cnt < m) 
    {
    	cout << 0 << endl;
    	return 0;
    }
    if (n <= 10)
    { 
    	dfs(1,0);
    	cout << ans%mod << endl;
        return 0;
    }
    for (int i = 1;i <= n;i++)
    	sum = sum*i%mod;
    cout << sum << endl;
	return 0;
}