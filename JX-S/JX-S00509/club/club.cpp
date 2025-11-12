#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int t,n,a[N][5],b[N][5],cnt[5];
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
  freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
  cin >> t;
  while(t--) {
	  cin >> n;
	  long long sum = 0;
      vector<int> v[4];
      memset(cnt,0,sizeof(cnt));
	  for(int i = 1; i <= n; i++) {
		  for(int j = 1; j <= 3; j++) {
			  cin >> a[i][j];
			  b[i][j] = a[i][j];
		  }
		  sort(b[i] + 1,b[i] + 4);
		  for(int j = 1; j <= 3; j++)  {			
			   if(a[i][j] == b[i][3]) {
				   cnt[j]++,v[j].push_back(i),sum += b[i][3];
				   break;
			}
		  }
	  }
	  int mx = 0,e = 0;
	  for(int i = 1; i <= 3; i++) 
		  if(mx < cnt[i]) mx = cnt[i],e = i;
	if(mx <= n / 2) {
		cout << sum << '\n';
		continue;
	}
	vector<pair<int,int>> v2;
	  for(int i = 0; i < v[e].size(); i++) {
		  int id = v[e][i],k = 0;
		  for(int j = 1; j <= 3; j++) {
			  if(a[id][j] == b[id][2]) {
				  k = j;
				  break;
			  }
		  }
		  v2.push_back({b[id][3] - b[id][2],k});
	  }
	  sort(v2.begin(),v2.end());
	  for(int i = 0; i < mx - n / 2; i++){
		  int x = v2[i].first,y = v2[i].second;
		  sum -= x;
		  cnt[y]++;
      }
		  cout << sum << '\n';
  }
  return 0;
}/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
1 
4
0 1 0
0 1 0
0 2 0
0 2 0
1
2 
10 9 8
4 0 0
*/
