#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, q;

string s1[N], s2[N], tt1[N], tt2[N];

unordered_map<int, int> rec;

pair<int, int> pos[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  int subB = 1;
  for(int i = 1; i <= n; i++){
    cin >> s1[i] >> s2[i];
  }
  for(int i = 1; i <= q; i++){
    cin >> tt1[i] >> tt2[i];
  }
//  cerr << subB << "Debug\n";
  for(int i = 1; i <= q; i++){
    string t1 = tt1[i], t2 = tt2[i];
    int p1 = pos[i].first, p2 = pos[i].second;
    if(t1.size() != t2.size()){
      cout << 0 << "\n";
      continue;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
      int p = t1.find(s1[i]);
      if(p != -1){
        string ttt = t1;
        for(int j = 0; j < s2[i].size(); j++){
          ttt[p++] = s2[i][j];
        }
        if(ttt == t2){
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
