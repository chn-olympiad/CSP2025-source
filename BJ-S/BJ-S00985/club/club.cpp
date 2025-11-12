#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct node{
    int id;
    ll val;
}m1[N], m2[N], m3[N];
bool cmp(node aa, node bb){
    return aa.val > bb.val;
}
int t;
int n;
int l1, l2, l3;
int cnt, cnt1, cnt2, cnt3;
int ans;
int k;
ll a[N][4];
bool vis[N];
void dfs(int step, int sum){
    if(step > n){
        ans = max(ans, sum);
        return ;
    }
    if(cnt1 < k){
        cnt1 ++;
        dfs(step + 1, sum + a[step][1]);
        cnt1 --;
    }
    if(cnt2 < k){
        cnt2 ++;
        dfs(step + 1, sum + a[step][2]);
        cnt2 --;
    }
    if(cnt3 < k){
        cnt3 ++;
        dfs(step + 1, sum + a[step][3]);
        cnt3 --;
    }
    return ;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t --){
        cin >> n;
        k = n / 2;
        if(n > 30){
            for(int i = 1; i <= n; i ++){
                cin >> a[i][1] >> a[i][2] >> a[i][3];
                m1[i].id = i;
                m1[i].val = a[i][1];
                m2[i].id = i;
                m2[i].val = a[i][2];
                m3[i].id = i;
                m3[i].val = a[i][3];
                vis[i] = false;
            }
            sort(m1 + 1, m1 + n + 1, cmp);
            sort(m2 + 1, m2 + n + 1, cmp);
            sort(m3 + 1, m3 + n + 1, cmp);
            cnt = 0;
            cnt1 = 0;
            cnt2 = 0;
            cnt3 = 0;
            l1 = 1;
            l2 = 1;
            l3 = 1;
            ans = 0;
            while(true){
                if(cnt >= n){
                    break;
                }
                while(vis[m1[l1].id]){
                    l1 ++;
                }
                while(vis[m2[l2].id]){
                    l2 ++;
                }
                while(vis[m3[l3].id]){
                    l3 ++;
                }
                int j = 0;
                if(cnt1 < k){
                    int p = m1[l1].val;
                    j = max(p, j);
                }
                if(cnt2 < k){
                    int p = m2[l2].val;
                    j = max(p, j);
                }
                if(cnt3 < k){
                    int p = m3[l3].val;
                    j = max(p, j);
                }
                ans += j;
                if(j == m1[l1].val){
                    vis[m1[l1].id] = true;
                    cnt1 ++;
                    cnt ++;
                    l1 ++;
                }
                else if(j == m2[l2].val){
                    vis[m2[l2].id] = true;
                    cnt2 ++;
                    cnt ++;
                    l2 ++;
                }
                else{
                    vis[m3[l3].id] = true;
                    cnt3 ++;
                    cnt ++;
                    l3 ++;
                }
            }
            cout << ans << endl;
        }
        else{
            for(int i = 1; i <= n; i ++){
                cin >> a[i][1] >> a[i][2] >> a[i][3];
            }
            ans = 0;
            cnt1 = 0;
            cnt2 = 0;
            cnt3 = 0;
            dfs(1, 0);
            cout << ans << endl;
        }
    }
    return 0;
}
