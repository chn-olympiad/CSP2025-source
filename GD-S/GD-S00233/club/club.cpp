#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
int n;
struct node{
	int a , b , c;
}num[N];
bool cmp1(node x , node y)
{
	return x.a > y.a;
}
bool cmp2(node x , node y)
{
	return (x.a - x.b) > (y.a - y.b);
}
//long long dp[3][N][N];
//dp[i][j][k]:
//i是选到第几个
//j是a部门人数
//k是b部门人数
//(i-j-k)是c部门人数
long long ans;
inline void dfs(int now , int A , int B , long long sum)
{
	if (now > n)
	{
		ans = max(ans , sum);
		return ;
	}
	if (A < n / 2)
	{
		dfs(now + 1 , A + 1 , B , sum + num[now].a);
	}
	if (B < n / 2)
	{
		dfs(now + 1 , A , B + 1 , sum + num[now].b);
	}
	if (now - A - B < n / 2)
	{
		dfs(now + 1 , A , B , sum + num[now].c);
	}
	return ;	
} 
bool cmp3(node x , node y)
{
	return max(x.a , max(x.b , x.c)) > max(y.a , max(y.b , y.c));
}
void solve()
{
	ans = 0;
	bool f_A = true;
	bool f_B = true;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num[i].a >> num[i].b >> num[i].c;
		if (num[i].b != 0)
		{
			f_A = false;
		}
		if (num[i].c != 0)
		{
			f_A = false;
			f_B = false;
		}
	}
	if (f_A)
	{
		sort(num + 1 , num + 1 + n , cmp1);
		for (int i = 1; i <= n / 2; ++i)
		{
			ans += num[i].a;
		}
		cout << ans << endl;
		return ;
	}else if (f_B)
	{
		sort(num + 1 , num + 1 + n, cmp2);
		for (int i = 1; i <= n; ++i)
		{
			if (i <= n / 2)
			{
				ans += num[i].a;
			}else{
				ans += num[i].b;
			}
		}
		cout << ans << endl;
		return ;
	}else if(n <= 10)
	{
		dfs(1 , 0 , 0 , 0);
		cout << ans << endl;
	}else{
		sort(num + 1 , num + 1 + n , cmp3);
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		long long ANS = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (max(num[i].a , max(num[i].b , num[i].c)) == num[i].a)
			{
				if (cnt1 < n / 2){
					ANS += num[i].a;
					cnt1++;
				}else if(num[i].b > num[i].c){
					ANS += num[i].b;
					cnt2++;
				}else{
					ANS += num[i].c;
					cnt3++;
				}
			}else if (max(num[i].a , max(num[i].b , num[i].c)) == num[i].b)
			{
				if (cnt2 < n / 2){
					ANS += num[i].b;
					cnt2++;
				}else if(num[i].a > num[i].c){
					ANS += num[i].a;
					cnt1++;
				}else{
					ANS += num[i].c;
					cnt3++;
				}
			}else
			{
				if (cnt3 < n / 2){
					ANS += num[i].c;
					cnt3++;
				}else if(num[i].b > num[i].a){
					ANS += num[i].b;
					cnt2++;
				}else{
					ANS += num[i].a;
					cnt1++;
				}
			}
		}
		cout << ANS;
	}
//	else if (n <= 200)
//	{
//		for (int i = 1; i <= n; ++i)
//		{
//			for (int j = 1; j <= n / 2; j++)
//			{
//				for (int k = 1; k <= n / 2; ++k)
//				{
//					dp[i % 2 + 1][j][k] = max(((j < n / 2) ? dp[i % 2][j - 1][k] + num[i].a) , max(((k < n / 2) ? dp[i % 2][j][k - 1] + num[i].b) , ((i - j - k < n / 2) ? dp[i % 2][j][k] + num[i].c)));
//				}
//			}
//		}
//		cout << dp[n][n / 2][n / 2] << endl;
//		for (int j = 1; j <= n / 2; j++)
//		{
//			for (int k = 1; k <= n / 2; ++k)
//			{
//				dp[0][j][k] = 0;
//				dp[1][j][k] = 0;
//				dp[2][j][k] = 0;
//			}
//		}
//		return ;
//	}
	return ;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
