#include<bits/stdc++.h>
using namespace std;

long long t;
long long n;
long long a[100005][5];

long long cnt[5];

long long ans;

void dfs(long long x,long long num)
{
	if(x > n)
	{
		ans = max(ans,num);
		return ;
	}
	
	for(long long i = 1; i <= 3; i++)
	{
		if(cnt[i] + 1 <= n / 2)
		{
			cnt[i]++;
			dfs(x + 1,num + a[x][i]);
			cnt[i]--;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		for(long long i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		
		dfs(1,0);
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
