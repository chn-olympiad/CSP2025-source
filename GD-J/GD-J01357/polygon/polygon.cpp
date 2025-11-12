#include<bits/stdc++.h>

using namespace std;
const int N = 5005;
int n, stick[N];
long long ans;
void dfs(int p, long long sum, int maxx)
{
	for(int i = p; i <= n; i++)
	{
		if(sum+stick[i]>max(maxx, stick[i])*2)
		{
			ans++;
		}
		dfs(i+1, sum+stick[i], max(maxx, stick[i]));
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> stick[i];
	}
	sort(stick+1, stick+n+1);
	dfs(1, 0, 0);
	cout << ans;
	
	return 0;
}
