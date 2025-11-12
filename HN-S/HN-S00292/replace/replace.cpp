#include <bits/stdc++.h>
using namespace std;
void File(){
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
}
const int kN = 2e5 + 7;
int n, Q;
string s[kN][2], tmp1, tmp2;
vector< vector<int> >nxt, nxt2; 
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> Q;
  nxt.resize(n + 1);
  nxt2.resize(n + 1);
  for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
  for(int i = 1; i <= n;i++){
    string tmp = " " + s[i][0];
    int t = 0, len = s[i][0].size();
    nxt[i].resize(len + 1);
    for(int j = 2; j <= len; j++){
      while(t && tmp[t + 1] != tmp[j]) t = nxt[i][t];
      if(tmp[t + 1] == tmp[j]) t++;
      nxt[i][j] = t;
    }
  }
  for(int i = 1; i <= n;i++){
    string tmp = " " + s[i][1];
    int t = 0, len = s[i][1].size();
    nxt2[i].resize(len + 1);
    for(int j = 2; j <= len; j++){
      while(t && tmp[t + 1] != tmp[j]) t = nxt2[i][t];
      if(tmp[t + 1] == tmp[j]) t++;
      nxt2[i][j] = t;
    }
  }
  for(int q = 1; q <= Q; q++){
    cin >> tmp1 >> tmp2;
    if(tmp1.size() != tmp2.size()){
      cout << 0 << '\n';
      continue;
    }
    int ans = 0, t, t2, len = tmp1.size();
    tmp1 = " " + tmp1, tmp2 = " " + tmp2;
    int L = len + 1, R = 0;
    for(int i = 1; i <= len; i++){
      if(tmp1[i] != tmp2[i]) L = min(L, i), R = max(R, i);
    }
    for(int i = 1; i <= n; i++){
      int len2 = s[i][0].size();
      if(len2 > len) continue;
      t = t2 = 0;
      for(int j = 1; j <= len; j++){
        while(t && s[i][0][t + 1 - 1] != tmp1[j]) t = nxt[i][t];
        if(s[i][0][t + 1 - 1] == tmp1[j]) ++t;
        while(t2 && s[i][1][t2 + 1 - 1] != tmp2[j]) t2 = nxt2[i][t2];
        if(s[i][1][t2 + 1 - 1] == tmp2[j]) ++t2;
        if(t == len2 && t2 == len2 && (j >= R && j - len2 + 1 <= L)){
          ++ans;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}