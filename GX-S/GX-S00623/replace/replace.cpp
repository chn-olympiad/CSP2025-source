#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 10;
using namespace std;

int n, q;
string s[N][5], t[5];
int pos[N][5], tpos[5];

void initB(int i){
  for(int j = 0; j < s[i][1].size(); j ++){
    if(s[i][1][j] == 'b'){
      pos[i][1] = j +1;
      break;
    }
  }
  for(int j = 0; j < s[i][2].size(); j ++){
    if(s[i][2][j] == 'b'){
      pos[i][2] = j +1;
      break;
    }
  }
}

void input(){
  cin>>n>>q;
  for(int i = 1; i <= n; i ++){
    cin>>s[i][1]>>s[i][2];
    initB(i);
  }
}

void solveB(){
  cin>>t[1]>>t[2];
  for(int j = 0; j < t[1].size(); j ++){
    if(t[1][j] == 'b'){
      tpos[1] = j +1;
      break;
    }
  }
  for(int j = 0; j < t[2].size(); j ++){
    if(t[2][j] == 'b'){
      tpos[2] = j +1;
      break;
    }
  }
  int res = 0;
  for(int i = 1; i <= n; i ++){
    if(pos[i][1] - pos[i][2] == tpos[1] - tpos[2] &&
       tpos[1] >= pos[i][1] &&
       tpos[2] >= pos[i][2] &&
       (int)t[1].size() - tpos[1] >= (int)s[i][1].size() - pos[i][1] &&
       (int)t[2].size() - tpos[2] >= (int)s[i][2].size() - pos[i][2]
      )
      res ++;
  }
  cout<<res<<"\n";
}

void solve(){
  input();
  for(int i = 1; i <= q; i ++)
    solveB();
}

signed main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  solve();

    return 0;
}
