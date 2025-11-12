#include<bits/stdc++.h>
using namespace std;
char ch[100005];
int c[100005];
int ord[15];
bool p[15];
int n,m;
long long ans = 0;
const int mod = 998244353;
int cnt0[100005];
bool check()
{
	int l[15];
	int num = n;
	int failed = 0;
	for(int i = 1;i <= n;i++) l[i] = c[ord[i]];//,cout << l[i] << ' ';
	for(int i = 1;i <= n;i++)
	{
		if(ch[i] == '0') num--,failed++;
		else if(failed >= l[i]) num--,failed++;
	}
//	for(int i = 1;i <= n;i++) cout << l[i] << ' ' << cnt0[i] << endl;
//	cout << num;
//	cout << endl;
//	cout << " | " << num << endl;
	if(num >= m) return 1;
	return 0;
}
void dfs(int depth)
{
	if(depth == n) ans = (ans + check()) % mod;
	for(int i = 1;i <= n;i++)
	{
		if(!p[i])
		{
			p[i] = 1;
			ord[depth + 1] = i;
			dfs(depth + 1);
			p[i] = 0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> (ch + 1);
	for(int i = 1;i <= n;i++)
	{
		int tmp = 0;
		for(int k = 1;k <= i;k++) if(ch[k] == '0') tmp++;
		cnt0[i] = tmp;
	}
	int sum = 0;
	for(int i = 1;i <= n;i++) cin >> c[i],sum += (ch[i] - '0');
	
	dfs(0);
	cout << ans << endl;
	return 0;
}
