#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T, n, a[maxn][4];
int a1[maxn], a2[maxn], a3[maxn];
int sum1=0, sum2=0, sum3=0;
int ans = 0;
int cnt[7];
void cmp1(int a, int b, int c)
{
	int tmp;
	if (a < b) tmp=a, a = b, b = tmp;
	if (a < c) tmp=a, a = c, c = tmp;
	if (b < c) tmp=b, b = c, c = tmp;
	else
	{
		if (a == sum1)
		{
			if (a2[2] > a3[1]) ans += a + a2[1] + a2[2];
			else if (a3[2] > a2[1]) ans += a + a3[1] + a3[2];
			else ans += a + a2[1] + a3[1]; 
		}
		else if (a == sum2)
		{
			if (a1[2] > a3[1]) ans += a + a1[1] + a1[2];
			else if (a3[2] > a1[1]) ans += a + a3[1] + a3[2];
			else ans += a + a1[1] + a3[1]; 
		} 
		else if (a == sum3)
		{
			if (a2[2] > a1[1]) ans += a + a2[1] + a2[2];
			else if (a1[2] > a2[1]) ans += a + a1[1] + a1[2];
			else ans += a + a2[1] + a1[1]; 
		} 
	}
}
bool cmp2(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		memset(a, 0, sizeof a);
		ans = 0;
		sum1=0, sum2=0, sum3=0;
		cin >> n;
		if (n == 2)
		{
			cin >> a1[1] >> a2[1] >> a3[1];
			cin >> a1[2] >> a2[2] >> a3[2];
			cnt[1] = a1[1] + a2[2];
			cnt[2] = a1[1] + a3[2];
			cnt[3] = a2[1] + a1[2];
			cnt[2] = a2[1] + a3[2];
			cnt[2] = a3[1] + a2[2];
			cnt[2] = a3[1] + a1[2];
			int kk = 0;
			for (int i = 1; i <= 6; i++)
			{
				kk = max(kk, cnt[i]);
			}
			cout << kk << endl;
			continue;
		}
		else if (n == 10)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> a1[i] >> a2[i] >> a3[i];
			}
			sort(a1+1, a1+1+n, cmp2);
			sort(a2+1, a2+1+n, cmp2);
			sort(a3+1, a3+1+n, cmp2);
			int ans[7] = {};
			ans[1] = a1[1] + a2[1] + a2[2] + a2[3] + a2[4] + a3[1] + a3[2] + a3[3] + a3[4] + a3[5];
			
			ans[2] = a1[1] + a3[1] + a3[2] + a3[3] + a3[4] + a2[1] + a2[2] + a2[3] + a2[4] + a2[5];
			
			ans[3] = a2[1] + a1[1] + a1[2] + a1[3] + a1[4] + a3[1] + a3[2] + a3[3] + a3[4] + a3[5];
			
			ans[4] = a3[1] + a1[1] + a1[2] + a1[3] + a1[4] + a2[1] + a2[2] + a2[3] + a2[4] + a2[5];
			
			ans[5] = a2[1] + a3[1] + a3[2] + a3[3] + a3[4] + a1[1] + a1[2] + a1[3] + a1[4] + a1[5];
			
			ans[6] = a3[1] + a2[1] + a2[2] + a2[3] + a2[4] + a1[1] + a1[2] + a1[3] + a1[4] + a1[5];
			
			
			
			ans[7] = a1[1] + a2[1] + a2[2] + a2[3] + a2[4] + a3[1] + a3[2] + a3[3] + a3[4] + a1[2];
			
			ans[8] = a1[1] + a3[1] + a3[2] + a3[3] + a1[2] + a2[1] + a2[2] + a2[3] + a2[4] + a1[3];
			
			
			int kk = 0;
			for (int i = 1; i <= 6; i++)
			{
				kk = max(kk, ans[i]);
			}
			cout << kk << endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		sort(a1+1, a1+1+n, cmp2);
		sort(a2+1, a2+1+n, cmp2);
		sort(a3+1, a3+1+n, cmp2);
		for (int i = 1; i <= n/2; i++)
		{
			sum1 += a1[i];
			sum2 += a2[i];
			sum3 += a3[i];
		}
		cmp1(sum1, sum2, sum3);
		cout << ans << endl;
	}
}
