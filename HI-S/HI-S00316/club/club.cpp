#include <bits/stdc++.h>
using namespace std;
int T,n,sum;
long long  a[100005][4];
void dp(int k,int a1,int a2,int a3,int ans,int n)
{
	if (ans > sum)
	{
		sum = ans;
	}
	if (k > n)
	{
		return;
	}
	if (a1 < n / 2)
	{
		dp(k + 1,a1 + 1,a2,a3,ans + a[k][1],n);
	}
	if (a2 < n / 2)
	{
		dp(k + 1,a1,a2 + 1,a3,ans + a[k][2],n);
	}
	if (a2 < n / 2)
	{
		dp(k + 1,a1,a2,a3 + 1,ans + a[k][3],n);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("clude.out","w",stdout);
	cin >> T;
	while(T--)
	{
		sum = 0;
		for (int i = 1;i <= n;i++)
		{
			a[i][1] = 0,a[i][2] = 0,a[i][2] = 0;
		}
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dp(1,0,0,0,0,n);
		cout << sum << endl;
	}
	return 0;
 } 
