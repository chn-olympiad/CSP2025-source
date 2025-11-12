#include <bits/stdc++.h>
using namespace std;

const int _ = 505,Mod = 998244353;

int n,m,flag = 1;
string s;

int a[_],b[_];
int ans;

namespace Task1 {
  int p[15],vis[15];
  void DFS(int now) {
    if(now > n) {
  	  int cnt1 = 0,cnt2 = 0;
  	  for(int i = 1;i <= n;i++) {
  	    if(cnt2 >= b[p[i]] || a[i] == 0) cnt2++;
  	    else cnt1++;
	  }
	  if(cnt1 >= m) ans++;
	  return;
    }
    for(int i = 1;i <= n;i++) {
  	  if(!vis[i]) p[now] = i,vis[i] = 1,DFS(now + 1),p[now] = 0,vis[i] = 0;
    }
  }
  void Run() {
  	DFS(1);
  	cout << ans << '\n';
  	return;
  }
}

namespace Task2 {
  void Run() {
  	int flag = (b[1] != 0);
  	for(int i = 1;i <= n;i++) {
  	  flag &= (a[i] == 1);
	}
	if(!flag) cout << 0 << '\n';
	else {
	  int mul = 1;
	  for(int i = 1;i <= n;i++) {
	  	mul *= i;
	  }
	  cout << mul << '\n';
	}
  }
}

int main() {
  cin >> n >> m >> s;
  s = ' ' + s;
  for(int i = 1;i <= n;i++) a[i] = s[i] - '0',flag &= a[i];
  for(int i = 1;i <= n;i++) {
  	cin >> b[i];
  }
  sort(b + 1,b + 1 + n);
  if(n <= 10) Task1::Run();
  else if(m == n) Task2::Run();
  return 0;
}
