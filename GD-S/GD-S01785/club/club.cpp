#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k, ans=0;
int w1[100005], w2[100005], w3[100005];
	
void dfs(int s1, int s2, int s3, int sum, int mem)
{
	if(mem > n+1) return;
	if(s1+1 <= k) dfs(s1+1, s2, s3, sum+w1[mem], mem+1);
	if(s2+1 <= k) dfs(s1, s2+1, s3, sum+w2[mem], mem+1);
	if(s3+1 <= k) dfs(s1, s2, s3+1, sum+w3[mem], mem+1);
	ans = max(ans, sum);
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		k = n / 2;
		for(int i=1;i<=n;i++)
		{
			cin >> w1[i] >> w2[i] >> w3[i];
		}
		dfs(0,0,0,0,1);
		cout << ans << endl;
	}
} 
