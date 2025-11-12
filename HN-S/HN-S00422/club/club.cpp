#include <bits/stdc++.h>
using namespace std;
int t,n;
struct S{
   int v,id;
}a[100005][5];
bool cmp(S i,S j) {
    return i.v > j.v;
}
struct node{
   int v,pos;
   bool operator > (node o) const {
       return v > o.v;
   }
};
priority_queue<node,vector<node>,greater<node> > pq[5];
int maxn = 0;
void dfs(int x,int cnt1,int cnt2,int cnt3,int sum) {
    if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
    if (x == n + 1) {
       maxn = max(maxn,sum);
       return;
    }
    dfs(x + 1,cnt1 + 1,cnt2,cnt3,sum + a[x][1].v);
    dfs(x + 1,cnt1,cnt2 + 1,cnt3,sum + a[x][2].v);
    dfs(x + 1,cnt1,cnt2,cnt3 + 1,sum + a[x][3].v);
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 20) {
           for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= 3; j++) {
                   cin >> a[i][j].v;
               }
           }
           maxn = 0;
           dfs(1,0,0,0,0);
           cout << maxn << '\n';
           continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j].v;
                a[i][j].id = j;
            }
            sort (a[i] + 1,a[i] + 1 + 3,cmp);
        }
        for (int i = 1; i <= n; i++) {
            if (pq[a[i][1].id].size() + 1 > n / 2) {
               node now = pq[a[i][1].id].top();
               int x = now.v,p = now.pos,tt = 0,f = 0;
               int maxx = 0;
               if (pq[a[p][2].id].size() + 1 > n / 2) {
                  node noww = pq[a[p][2].id].top();
                  int xx = noww.v,pp = noww.pos;
                  if (xx < a[p][2].v) {
                      maxx = a[p][2].v - xx;
                      maxx += a[pp][3].v;
                  }
                  if (maxx > a[p][3].v) {
                     tt += maxx;
                     f = 1;
                  } else {
                     tt += a[p][3].v;
                     f = 2;
                  }
               } else {
                  tt += a[p][2].v;
               }
               maxx = 0;
               int ttt = 0;
               node noww = pq[a[i][2].id].top();
               int xx = noww.v,pp = noww.pos,ppp=0,xxx=0,ff = 0;
               if (pq[a[i][2].id].size() + 1 > n / 2) {
                  node nowww = pq[a[i][2].id].top();
                  xxx = nowww.v,ppp = nowww.pos;
                  if (xxx < a[i][2].v) {
                     maxx = a[i][2].v - xxx;
                     maxx += a[ppp][3].v;
                  }
                  if (maxx > a[i][3].v) {
                     ff = 1;
                     ttt += maxx;
                  } else {
                     ff = 2;
                     ttt += a[i][3].v;
                  }
               } else {
                  ttt += a[i][2].v;
               }
               int tttt = tt + a[i][1].v - x;
               if (tttt > ttt) {
                  if (tt == a[p][2].v) {
                     pq[a[p][2].id].push(node{a[p][2].v,p});
                  }
                  if (f == 1) {
                     pq[a[p][2].id].pop();
                     pq[a[p][2].id].push(node{a[p][2].v,p});
                     pq[a[pp][3].id].push(node{a[pp][3].v,pp});
                  }
                  if (f == 2) {
                    pq[a[p][3].id].push(node{a[p][3].v,p});
                  }
                  pq[a[i][1].id].pop();
                  pq[a[i][1].id].push(node{a[i][1].v,i});
              } else {
                  if (tt == a[i][2].v) {
                     pq[a[i][2].id].push(node{a[i][2].v,i});
                   } else {
                       if (ff == 1) {
                          pq[a[i][2].id].pop();
                          pq[a[i][2].id].push(node{a[i][2].v,i});
                          pq[a[ppp][3].id].push(node{a[ppp][3].v,ppp});
                       }
                       if (ff == 2) {
                          pq[a[i][3].id].push(node{a[i][3].v,i});
                       }
                   }
                   pq[a[i][1].id].pop();
                   pq[a[i][1].id].push(node{a[i][1].v,i});
                }
            } else {
                 pq[a[i][1].id].push(node{a[i][1].v,i});
            }
        }
        int ans = 0;
        for (int i = 1; i <= 3; i++) {
            while (!pq[i].empty()) ans += pq[i].top().v,pq[i].pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
