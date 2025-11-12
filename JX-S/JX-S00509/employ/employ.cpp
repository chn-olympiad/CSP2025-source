#include <bits/stdc++.h>
using namespace std;
const int M = 2 * 1e6 + 10,N = 1e3 + 15;
int t,n,q;
char a[N];
int vis[N],b[N],c[N],ans = 0;
bool check() {
	int cnt = 0,res = 0;
	  for(int i = 1; i <= n; i++) {
		  if(res >= b[i]) {
			  res++;
		    continue;
	      }
		  if(a[i] == '1') {
			  cnt++;
			} else res++;
		 }
    return cnt >= q;
}
void dfs(int cc) {
	if(cc > n) {
		if(check()) ans++;
		return; 
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			b[cc] = c[i];
			vis[i] = 1;
			dfs(cc + 1);
			b[cc] = 0;
			vis[i] = 0;
		}
	}
}
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
   cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> c[i];
   dfs(1);
   cout << ans;
  return 0;
}/*
3 2
101
1 1 2
*/
