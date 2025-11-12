#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  freopen("club5.in","r",stdin);
  freopen("club.out","w",stdout);
  int tt;
  cin >> tt;
  while(tt--) {
  	solve();
  }
  return 0;
}

const int _ = 1e5 + 5;

int n;
int a[_][4];

namespace Task1 {
  int dp[205][105][105];
  void Run() {
  	for(int i = 1;i <= n;i++) {
  	  for(int j = 0;j <= n / 2;j++) {
  	    for(int k = 0;k <= n / 2;k++) {
  	      dp[i][j][k] = 0;
		}
	  }
	}
  	for(int i = 1;i <= n;i++) {
  	  for(int j = 0;j <= min(i,n / 2);j++) {
  	    for(int k = 0;k <= min(i - j,n / 2);k++) {
  	      if(j) dp[i][j][k] = dp[i - 1][j - 1][k] + a[i][1];
  	      if(k) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k - 1] + a[i][2]);
  	      if(i - j - k) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k] + a[i][3]);
		}
	  }
	}
	int ans = 0;
//  	for(int i = 1;i <= n;i++) {
//  	  for(int j = 0;j <= min(i,n / 2);j++) {
//  	    for(int k = 0;k <= min(i - j,n / 2);k++) {
//  	      cout << "[" << i << "," << j << "," << k << "]" << dp[i][j][k] << '\n';
//		}
//	  }
//	}
	for(int i = 0;i <= n / 2;i++) {
	  for(int j = 0;j <= n / 2;j++) {
	  	if(i + j < n / 2) continue;
	  	ans = max(ans,dp[n][i][j]);
	  }
	}
	cout << ans << '\n';
  }
}

namespace Task2 {
  void Run() {
  	int ans = 0;
  	vector<int> vec;
  	for(int i = 1;i <= n;i++) {
  	  ans += a[i][1];
  	  vec.push_back(a[i][1] - a[i][2]);
	}
	sort(vec.begin(),vec.end());
	for(int i = 0;i < n / 2;i++) {
	  ans -= vec[i];
	}
	cout << ans << '\n';
  }
}

namespace Task3 {
  void Run() {
  	int ans = 0;
    for(int i = 1;i <= n;i++) {
      ans += max(a[i][1],max(a[i][2],a[i][3]));
	}
	cout << ans << '\n';
  }
}

int ans;

void solve() {
  cin >> n;
  int flag1 = 1,flag2 = 1;
  ans = 0;
  for(int i = 1;i <= n;i++) {
  	cin >> a[i][1] >> a[i][2] >> a[i][3];
  	flag1 &= (a[i][3] == 0); 
  }
  if(n <= 200) Task1::Run();
  else if(flag1) Task2::Run();
  else Task3::Run();
}

