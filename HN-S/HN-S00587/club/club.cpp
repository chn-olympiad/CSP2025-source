#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

struct node{
  int x, y, z;
} a[maxn];

int t, n, ans, s[5], b[5], u[maxn], tl[maxn], c[maxn][3];

bool cmp(node u, node v){ // 123
  if(u.x != v.x) return u.x > v.x;
  if(u.y != v.y) return u.y > v.y;
  return u.z > v.z;
}

bool cmp2(node u, node v){ // 213
  if(u.y != v.y) return u.y > v.y;
  if(u.x != v.x) return u.x > v.x;
  return u.z > v.z;
}

bool cmp3(node u, node v){ // 312
  if(u.z != v.z) return u.z > v.z;
  if(u.x != v.x) return u.x > v.x;
  return u.y > v.y;
}

int S(){
  s[1] = s[2] = s[3] = 0;
  int tot = 0;
  for(int i = 1; i <= n; i++){
    s[u[i]]++;
    if(s[u[i]] > n / 2) return 0;
    if(u[i] == 1) tot += a[i].x;
    if(u[i] == 2) tot += a[i].y;
    if(u[i] == 3) tot += a[i].z;
  }
  return tot;
}

void F(int x){
  if(x > n){
    ans = max(ans, S());
    return;
  }
  for(int i = 1; i <= 3; i++){
    u[x] = i;
    F(x + 1);
    u[x] = 0;
  }
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  for(cin >> t; t; t--){
    cin >> n;
    int f3 = 1;
    for(int i = 1; i <= n; i++){
      cin >> a[i].x >> a[i].y >> a[i].z;
      c[i][1] = a[i].x, c[i][2] = a[i].y, c[i][3] = a[i].z;
      if(a[i].y != a[i].z || !a[i].y) f3 = 0;
    }
    ans = 0;
    if(n <= 10){
      ans = 0;
      F(1);
      cout << ans << '\n';
      continue;
    }
    s[1] = s[2] = s[3] = 0;
    sort(a + 1, a + n + 1, cmp);
    if(f3){
      for(int i = 1; i <= n / 2; i++){
        ans += a[i].x;
      }
      cout << ans << '\n';
      continue;
    }
    if(n <= 5000){
      for(int i = 1; i <= n; i++){
        b[1] = a[i].x, b[2] = a[i].y, b[3] = a[i].z;
        int p = 1;
        for(int j = 1; j <= 3; j++){
          if(b[j] > b[p] || (b[j] == b[p] && s[j] == s[p])){
            p = j;
          }
        }
        if(s[p] < n / 2){
          s[p]++, ans += b[p], tl[i] = p;
        } else {
          int mi = 1e9, pos = 1, g = 0;
          for(int j = 1; j < i; j++){
            if(tl[j] == p){
              for(int k = 1; k <= 3; k++){
                if(k != p && c[j][p] - c[j][k] < mi && b[k] < n / 2){
                  mi = c[j][p] - c[j][k], pos = j, g = k;
                }
              }
            }
          }
          if(b[p] > mi){
            ans += b[p] - mi, s[g]++;
            tl[pos] = g, tl[i] = p;
          } else {
            pos = 0;
            for(int j = 1; j <= 3; j++){
              if(s[j] < n / 2 && b[j] > b[pos]){
                pos = j;
              }
            }
            tl[i] = pos, ans += b[pos], s[pos]++;
          }
        }
      }
      cout << ans << '\n';
      continue;
    }
    int tot = 0;
    for(int i = 1, l; i <= n; i++){
      if(s[1] < n / 2){
        s[1]++, tot += a[i].x;
      } else {
        if((a[i].y > a[i].z && s[2] < n / 2) || (a[i].y == a[i].z && s[2] < s[3])) {
          s[2]++, tot += a[i].y;
        } else {
          s[3]++, tot += a[i].z;
        }
      }
    }
    ans = max(ans, tot);
    sort(a + 1, a + n + 1, cmp2);
    tot = s[1] = s[2] = s[3] = 0;
    for(int i = 1, l; i <= n; i++){
      if(s[2] < n / 2){
        s[2]++, tot += a[i].y;
      } else {
        if((a[i].x > a[i].z && s[1] < n / 2) || (a[i].x == a[i].z && s[1] < s[3])) {
          s[1]++, tot += a[i].x;
        } else {
          s[3]++, tot += a[i].z;
        }
      }
    }
    ans = max(ans, tot);
    sort(a + 1, a + n + 1, cmp3);
    tot = s[1] = s[2] = s[3] = 0 ;
    for(int i = 1, l; i <= n; i++){
      if(s[3] < n / 2){
        s[3]++, tot += a[i].z;
      }  else {
        if((a[i].x > a[i].y && s[1] < n / 2) || (a[i].x == a[i].y && s[1] < s[2])) {
          s[1]++, tot += a[i].x;
        } else {
          s[2]++, tot += a[i].y;
        }
      }
    }
    ans = max(ans, tot);
    cout << ans << '\n';
  }
  return 0;
}

//Ren5Jie4Di4Ling5%
