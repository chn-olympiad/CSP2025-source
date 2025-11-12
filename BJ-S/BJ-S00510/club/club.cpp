#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int t, n, a[100005][5];
struct node{
    int id, cha;
}s[100005];
bool cmp(node x, node y){
    return x.cha > y.cha;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        int o[5] = {0}, ans = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            s[i].id = i;
            s[i].cha = max(max(a[i][1], a[i][2]), a[i][3]);
            int u = 0;
            if(a[i][1] == s[i].cha){
                u = max(a[i][2], a[i][3]);
            }
            else if(a[i][2] == s[i].cha){
                u = max(a[i][1], a[i][3]);
            }
            else if(a[i][3] == s[i].cha){
                u = max(a[i][2], a[i][1]);
            }
            s[i].cha -= u;
        }
        sort(s+1, s+n+1, cmp);
        for(int i = 1;i <= n;i++){
            int j = s[i].id;
            int l1 = max(max(a[j][1], a[j][2]), a[j][3]);
            int l2 = a[j][1] + a[j][2] + a[j][3] - l1 - min(min(a[j][1], a[j][2]), a[j][3]);
            int p1, p2;
            if(l1 == a[j][1]){
                p1 = 1;
            }
            if(l1 == a[j][2]){
                p1 = 2;
            }
            if(l1 == a[j][3]){
                p1 = 3;
            }
            if(l2 == a[j][1]){
                p2 = 1;
            }
            if(l2 == a[j][2]){
                p2 = 2;
            }
            if(l2 == a[j][3]){
                p2 = 3;
            }
            if(o[p1] < n / 2){
                ans += l1;
                o[p1]++;
            }
            else{
                ans += l2;
                o[p2]++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
