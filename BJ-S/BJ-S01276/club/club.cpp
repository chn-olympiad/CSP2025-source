#include <bits/stdc++.h>
using namespace std;
bool vis[100010];
struct node{
    int s1 , s2 , s3;
    bool vis;
};
node a[100010];
int n , t;
long long dp[100010][4] , ans = 0;
int mx3(node a){
    return max(a.s1 , max(a.s2 , a.s3));
}
int minn(int str , int ed , int p){
    int re = 0x3f3f3f3f;
    for (int i = str ; i < ed ; i ++){
        if (!a[i].vis){
            int aa;
            p == 1 ? aa = a[i].s1 : p == 2 ? aa = a[i].s2 : aa = a[i].s3;
            re = min(re , aa);
        }
    }
    for (int i = str ; i < ed ; i ++){
        int aa;
        p == 1 ? aa = a[i].s1 : p == 2 ? aa = a[i].s2 : aa = a[i].s3;
        if (!a[i].vis && re == aa){
            a[i].vis = 1;
            break;
        }
    }
    return re;
}
bool cmp(node a , node b){
    return a.s1 > b.s1;
}
/*void dfs(int cx , int cy ,int y1 , int y2 , int y3){
        int ccc;
        cy == 1 ? ccc = a[cx].s1 , y1++ : cy == 2 ? ccc = a[cx].s2 , y2++ : ccc = a[cx].s3 , y3++;
    if (y1 > n / 2 || y2 > n / 2 || y3 > n / 2){
        return;
    }
    if (cx == )
    for (int i = 1 ; i <= 3 ; i ++){
        int aa;
        i == 1 ? aa = a[cx].s1 : i == 2 ? aa = a[cx].s2 : aa = a[cx].s3;
    }
}*/
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin >> t;
    while(t --){
        memset(a , 0 , sizeof(a));
        memset(dp , 0 , sizeof(dp));
        bool f = 0;
        ans = -1;
        cin >> n;
        for (int i = 1 ; i <= n ; i ++){
            cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
                        if (a[i].s2 != 0){
                            f = 1;
                        }
        }
                        if (n == 2){
                            cout << max(a[0].s1 + a[1].s2 , max(a[0].s2 + a[1].s3 , a[0].s1 + a[1].s3));
                            continue;
                        }else if (!f){
                            sort(a + 1 , a + n + 1 , cmp);
                            ans = 0;
                            for (int i = 1 ; i <= n / 2 ; i ++){
                                ans += a[i].s1;
                            }
                            continue;
                        }
        for (int i = 1 ; i <= n ; i ++){
            ans += mx3(a[i]);
        //cout << mx3(a[i]) << " ";
        }
        cout << ans << "\n";
    }
    return 0;
}
