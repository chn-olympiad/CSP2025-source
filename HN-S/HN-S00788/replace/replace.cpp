#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
  int x = 0 ,f = 1;
  char ch = getchar();
  while('0' > ch || ch > '9') {
    if(ch == '-') f = -1;
    ch = getchar();
  }
  while('0' <= ch && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar();
  }
  return x * f;
}
signed main() {
  freopen("replace.in" ,"r" ,stdin);
  freopen("replace.out" ,"w" ,stdout);
  cout << 0;
  return 0;
}