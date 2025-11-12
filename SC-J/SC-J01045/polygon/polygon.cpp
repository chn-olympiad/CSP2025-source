#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
long long a[N],pre[N],dp[5005][5005];
long long num;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=3;j<=n;j++)
		{
			if(a[j]+pre[i]>a[j]*2)
			{
				dp[i][j]++;
			}
			dp[i][j]=dp[i][j]+dp[i][j-1];
		}
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
		num+=dp[i][n];
		num%=998244353;
	}
	cout<<num;
}