#include <bits/stdc++.h>
using namespace std;

int f[10005][5][5005];
int a[5][10005];
int c[100005]
int b[5],n,ans = 0;

void dfs(int step, int sum)
{
	if(step>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(b[1]<n/2){
		b[1]++;
		dfs(step+1,sum+a[1][step]);
		b[1]--;
	}
	if(b[2]<n/2){
		b[2]++;
		dfs(step+1,sum+a[2][step]);
		b[2]--;
	}
	if(b[3]<n/2){
		b[3]++;
		dfs(step+1,sum+a[3][step]);
		b[3]--;
	}
	
}

int main()
{
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		cin >> n;
		if(n>30)
		{
			int sum = 0;
			for(int i = 1; i <= n; i++)
			cin >> c[i]>> c[i]>> c[i];
			sort(c+1,c+n+1);
			for(int i = n; i >= n/2; i++)
				sum+=c[i];
			cout << sum << "\n";
		}
		else{
		for(int i = 1; i <= n; i++)
			cin >> a[1][i] >> a[2][i] >> a[3][i];
//		for(int i = 1; i <= 3; i++)
//		{
//			for(int j = 1; j <= n; j++)
//			{
//				for(int k = 0; k <= n/2; k++)
//				{
//					f[j][i][k]=f[j][i-1][k];
//					if(k>0)
//					f[j][i][k]=max(f[j-1][i-1][k-1]+a[i][j],f[j][i-1][k]);
//				}
//			}
//		}
		ans = 0;
		dfs(1,0);
		cout << ans << "\n";
		}
		
		
	}
	return 0;
}
