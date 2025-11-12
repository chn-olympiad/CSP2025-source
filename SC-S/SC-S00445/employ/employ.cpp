#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long int lli;
int ans;
int c[505];
int n,m;
string st;
int p[505];
int cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> st;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		p[i] = i;
	}
	do
	{
		cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			if(cnt >= c[p[i]])
			{
				cnt++;
			}
			else if(st[i - 1] == '0')
			{
				cnt++;
			}
		}
		if(n - cnt >= m)
		{
			ans++;
		}
	}
	while(next_permutation(p + 1,p + n + 1));
	cout << ans << endl;
	return 0;
}