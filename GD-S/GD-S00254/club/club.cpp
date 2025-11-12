#include<bits/stdc++.h>
#define int long long
using namespace std;
struct people{
	int score, num[4] = {0, 0, 0, 0};
}dp[100005][4];//表示到第i个人的时候 ，选j的最大值 
int a[100005][4];
void slove1()
{
	for(int i = 1; i <= n; i++){//第几个人 
		for(int j = 1; j <= 3; j++){//第几个社团 
			for(int k = 1; k <= 3; k++){//上一个人的选择 
				people x = dp[i - 1][k], y = dp[i][j];
//					cout << x.num[j];
				if(x.num[j] + 1 <= n / 2){//还能不能选 
//						cout << x.num[k];
//						cout << x.score + a[i][j];
					if(x.score + a[i][j] >= y.score){//如果更大 
						cout << k;
						y.score = x.score + a[i][j];//那么就要更新 
						for(int l = 1; l <= 3; l++)y.num[l] = x.num[l];
						y.num[j]++;
//							for(int l = 1; l <= 3; l++)cout << y.num[l] << " ";
					}
				}
				//不能选也要更新
				else{
					y.score = max(y.score, x.score);
					for(int l = 1; l <= 3; l++)y.num[l] = x.num[l];
				}
				dp[i - 1][k] = x, dp[i][j] = y;
				cout << "(" << y.score << " " << y.num[1] << " " << y.num[2] << " " << y.num[3] << ")";
			}
		}
		cout << endl;
	}
	cout << max(dp[n][1].score, max(dp[n][2].score, dp[n][3].score) ) << endl;
}
int te[100005]; 
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 100005; i++){
			for(int j = 0; j < 4; j++){
				dp[i][j].score = 0;
				dp[i][j].num[0] = dp[i][j].num[1] = dp[i][j].num[2] = dp[i][j].num[3] = 0;
			}
		}
		int n;
		cin >> n;
		int flag = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3]; 
			if(a[i][2] != 0)flag = 1;
			te[i] = a[i][1];
		}
		if(flag)solve1();
		else{
			sort(te + 1, te + n + 1);
			int sum = 0;
			for(int i = n; i > n / 2; i++){
				sum += te[i];
			}
			cout << sum << endl;
			
		}
	}
 } 
 /*
1 4
0 1 0
0 1 0
0 2 0
0 2 0
 */ 
