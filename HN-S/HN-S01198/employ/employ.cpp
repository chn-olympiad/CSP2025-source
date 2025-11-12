#include<bits/stdc++.h>

using namespace std;
const int MAXN = 505;
int n, m, c[MAXN], a[MAXN], b[MAXN];
string s;
signed main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  #ifndef QWQ
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  #endif
  cin >> n >> m >> s;
  for (int i = 1; i <= n; i++){
    cin >> b[i];
    a[i] = i;
  }
  s = ' ' + s;
  int ans = 0;
  do{
    int cnt = 0, qwq = 0;
    for (int i = 1; i <= n; i++){
      c[i] = b[a[i]];
    }
    for (int i = 1; i <= n; i++){
      if (cnt >= c[i]){
        cnt++;
        continue;
      }else if (s[i] == '0'){
        cnt++;
      }else {
        qwq++;
      }
    }
    ans += (qwq >= m);
//    cerr << qwq << '\n';
//    for (int i = 1; i <= n; i++){
//      cerr << c[i] << " \n"[i == n];
//    }
  }while(next_permutation(a + 1, a + n + 1));
  cout << ans;
  return 0;
}
/*
一切都结束了

全排列 8 分

3 年零 5 个多月的 OI 生涯，终点线近在眼前。

两次 J 一等，两次 S一等

初中近一年的停课

的确，我得到了许多

但我也失去了许多

所以

高中三年

不要让我再失去了 
*/























/*
漂流树洞在线求写信（为什么会出现在这里（雾））

学校编码 08A16

收信人 tbdsh

（应该不会有人看到这并且写吧） 
*/

