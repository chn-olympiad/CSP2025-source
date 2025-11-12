#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10, MAXL = 5e6 + 10, MAXM = 2e3 + 10;

int n, q, kmp[MAXN][MAXM];
long long ans, cnt;
string t1, t2, s1[MAXN], s2[MAXN];
vector<int> pos;

void Solve(int x){
  pos.clear();

  int n = t1.size() - 1, m = s1[x].size() - 1;
  for(int i = 1, j = 0; i <= n; i++){
    while(j && t1[i] != s1[x][j + 1]) j = kmp[x][j];

//    cout << t1[i] << ' ' << s1[x][j + 1] << ' ' << j << ' ' << m << '\n';

    if(t1[i] == s1[x][j + 1]) j++;
    if(j == m){

  //      cout << 111 << '\n';
//
      pos.push_back(i - j + 1);
      j = kmp[x][j];
    }
  }

 // cout << x << '\n';

  string s = "";

  for(int p: pos){
    s = " ";
    for(int i = 1; i < p; i++) s += t1[i];
    s += s2[x];
    for(int i = p + m; i <= n; i++) s += t1[i];

  //  cout << s << '\n' << t2 << '\n';

    if(s == t2) ans++;
  }
}

void Kmp(int x){
  int len = s1[x].size() - 1;
  for(int i = 1, j = 0; i <= len; i++){
    if(j && s1[x][i + 1] == s1[x][j + 1]) j = kmp[x][j];
    if(s1[x][i + 1] == s1[x][j + 1]) j++;
    kmp[x][i + 1] = j;
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> s1[i] >> s2[i];
    s1[i] = ' ' + s1[i];//, s2[i] = ' ' + s2[i];
  }

  for(int i = 1; i <= n; i++){
    Kmp(i);
  }

  while(q--){
    cin >> t1 >> t2;
    t1 = ' ' + t1, t2 = ' ' + t2;
    for(int i = 1; i <= n; i++){
   //   cout << s1[i] << ' ' << s2[i] << '\n';
      if(t1.size() - s1[i].size() + s2[i].size() + 1 == t2.size()){
        Solve(i);
      }
    }
    cout << ans << '\n';
    ans = 0;
  }
  return 0;
}
