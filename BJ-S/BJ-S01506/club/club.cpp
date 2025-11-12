#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid (l + r >> 1)
using namespace std;

const int N = 1e5 + 5;
int t, n, c1, c2, c3, ans;
priority_queue<int, vector<int>, greater<int>> q1, q2, q3;
int main(){
   //freopen("data.in", "r", stdin);
   //freopen("T1.out", "w", stdout);
   freopen("club.in", "r", stdin);
   freopen("club.out", "w", stdout);
   scanf("%d", &t);
   while(t--){
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        while(!q3.empty()) q3.pop();
        c1 = c2 = c3 = ans = 0;
       scanf("%d", &n);
       for (int i = 1; i <= n; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (x >= y && x >= z){
                q1.push(x - max(y, z));
                ans += x;
                if (c1 < n / 2){
                    c1++;
                }
                else{
                    int p = q1.top();
                    q1.pop();
                    ans -= p;
                }
            }
            else if (y >= x && y >= z){
                q2.push(y - max(x, z));
                ans += y;
                if (c2 < n / 2){
                    c2++;
                }
                else{
                    int p = q2.top();
                    q2.pop();
                    ans -= p;
                }
            }
            else{
                q3.push(z - max(x, y));
                ans += z;
                if (c3 < n / 2){
                    c3++;
                }
                else{
                    int p = q3.top();
                    q3.pop();
                    ans -= p;
                }
            }
       }
       printf("%d\n", ans);
   }
   return 0;
}
