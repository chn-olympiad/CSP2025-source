#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 505;
int c[N];
string s;
int n,m;
bool flag[N];
int ans = 0;
void dfs(int step,int cnt1,int cnt2)
{
	if(step > n)
	{
		if(cnt1 >= m)ans++;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(flag[i])continue;
		flag[i] = true;
		if(c[i] <= cnt2 || s[step - 1] == '0')dfs(step + 1,cnt1,cnt2 + 1);
		else dfs(step + 1,cnt1 + 1,cnt2);
		flag[i] = false;	
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&c[i]);
	}
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
