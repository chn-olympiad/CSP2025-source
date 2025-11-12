#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ep emplace
#define eb emplace_back 
#define fr(a,b,c) for(int (a) = (b);(a) <= (c);a ++)
using namespace std;
const int N = 100100;
int T,n,a[N][5],cnt[5];
ll ans;
vector<int> mb[5];
priority_queue<int,vector<int>,greater<int>> q;
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  while(T --){
    while(q.size()) q.pop();
    fr(i,1,3) mb[i].clear(),cnt[i] = 0;
    ans = 0;
    cin >> n;
    fr(i,1,n) cin >> a[i][1] >> a[i][2] >> a[i][3];
    fr(i,1,n){
      fr(j,1,3){
        if(a[i][j] >= a[i][1] && a[i][j] >= a[i][2] && a[i][j] >= a[i][3]){
          ans += a[i][j],cnt[j] ++;
          mb[j].eb(i);
          break;
        }
      }
    }
    fr(j,1,3){
      if(cnt[j] > n / 2){
        for(auto i : mb[j]){
          if(j == 1) q.ep(a[i][1] - max(a[i][2],a[i][3]));
          if(j == 2) q.ep(a[i][2] - max(a[i][1],a[i][3]));
          if(j == 3) q.ep(a[i][3] - max(a[i][1],a[i][2]));
        }
        fr(i,1,cnt[j] - n / 2){
          ans -= q.top();
          q.pop();
        }
        break;
      }
    }
    printf("%lld\n",ans);
  }
  return 0;
}
/*
14:37 敲完缺省源，开始看 pdf
2048 bitset?
14:40 idea
14:47 finish
14:52 test end
15:07: B,D   B 1~20

15:22 C,    B idea
15:33 finish
15:48 fake.
15:55 why fake?
16:04 finish


16:47 D m=1/n finish 216pts
17:03 D n<=18 finish 236pts




*/