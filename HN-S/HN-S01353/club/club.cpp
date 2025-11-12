#include <bits/stdc++.h> 
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

ifstream fin("club.in");
ofstream fout("club.out");

const int kMaxN = 2e5 + 5;

struct Peo {
  int a, b, c;
} a[kMaxN];

int T, n, vis[kMaxN];
priority_queue<Pii> pty, cch, pq;

int Max(Peo x) {
  return max({x.a, x.b, x.c});
}

int Get_ans() {
  LL ans = 0, cnta = 0, cntb = 0, cntc = 0;
  fin >> n;
  for(; !pty.empty(); pty.pop());
  for(; !cch.empty(); cch.pop());
  for(; !pq.empty(); pq.pop());
  for(int i = 1; i <= n; i++) {
    vis[i] = 0;
    fin >> a[i].a >> a[i].b >> a[i].c;
    cnta += (a[i].a == Max(a[i]));
    cntb += (a[i].b == Max(a[i]));
    cntc += (a[i].c == Max(a[i]));
  }
  if(cntb * 2 > n) {
    swap(cntb, cnta);
    for(int i = 1; i <= n; i++) {
      swap(a[i].a, a[i].b);
    }
  } else if(cntc * 2 > n) {
    swap(cnta, cntc);
    for(int i = 1; i <= n; i++) {
      swap(a[i].a, a[i].c);
    } 
  } else if(cnta * 2 <= n) {
    for(int i = 1; i <= n; i++) {
      ans += Max(a[i]);
    }
    return ans;
  }
//  cout << cnta << " " << cntb << "\n";
  for(int i = 1; i <= n; i++) {
    if(a[i].b == Max(a[i]) || a[i].c == Max(a[i])) {
      ans += Max(a[i]);
    } else {
      pq.push(mkp(a[i].a, i));
    }
  }
  for(int i = 1; (i << 1) <= n; i++) {
    ans += pq.top().fi;
    int tmp = pq.top().se;
    pq.pop();
    pty.push(mkp(a[tmp].b - a[tmp].a, tmp));
    cch.push(mkp(a[tmp].c - a[tmp].a, tmp));
  }
//  cout << ans << '\n';
  for(; !pq.empty(); ) {
    int pos = pq.top().se;
    pq.pop();
    for(; vis[pty.top().se]; pty.pop());
    for(; vis[cch.top().se]; cch.pop());
    if(max(a[pos].b, a[pos].c) > a[pos].a + max(cch.top().fi, pty.top().fi)) {
//      cout << pos << " " << "Direct\n";
      ans += max(a[pos].b, a[pos].c);
    } else {
      if(cch.top().fi > pty.top().fi) {
        ans += cch.top().fi + a[pos].a;
        int tmp = cch.top().se;
//        cout << tmp << " " << pos << " b\n";
        vis[tmp] = 1, cch.pop();
        cch.push(mkp(a[pos].c - a[pos].a, pos));
      } else {
        ans += pty.top().fi + a[pos].a;
        int tmp = pty.top().se;
//        cout << tmp << " " << pos << " c\n";
        vis[tmp] = 1, pty.pop();
        pty.push(mkp(a[pos].b - a[pos].a, pos));
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for(fin >> T; T--; ) {
    fout << Get_ans() << '\n';
  }
  return 0;
} 
/*
c 14230 3941 18854
b 12173 19429 15426
c 10974 4717 15290
b 4732 6608 4961
b 13198 13925 2137
c 10688 3092 16965
b 5356 19920 1471
c 11299 10796 13511
a 17932 12143 16407
c 5611 8100 16107
*/
