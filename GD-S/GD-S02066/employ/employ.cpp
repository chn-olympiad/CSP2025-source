#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
string s;
int c[502];
int vis[502];
void dfs(int day, int no, int sum)
{
	if(sum>=m)
		ans++;
	if(day>n)
		return;
	for(int i = 1;i<=n;i++)
	{
		if(no>=c[i] || vis[i])
			continue;
//		cout<<day<<" "<<i<<" ";
		vis[i]++;
		if(s[day]=='0')
			dfs(day+1, no+1, sum);
		else
			dfs(day+1, no, sum+1);
		vis[i]--;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++)
		cin>>c[i];
	dfs(1, 0, 0);
	cout<<ans;
	return 0; 
}
