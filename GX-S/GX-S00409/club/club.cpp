#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;
ll t,n,ans = 0;
int a[4][N] = {0};
bool flag1 = 0,flag2 = 0,flag3 = 0;

void dfs(int dep,ll co,int jj1,int jj2,int jj3)
{
    if (jj1 > n / 2 || jj2 > n / 2 || jj3 > n / 2) return ;
    if (dep > n){
        ans = max(ans,co);
        return ;
    }
    dfs(dep + 1,co + a[1][dep],jj1 + 1,jj2,jj3);
    dfs(dep + 1,co + a[2][dep],jj1,jj2 + 1,jj3);
    dfs(dep + 1,co + a[3][dep],jj1,jj2,jj3 + 1);
}

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1;i <= n;i++){
            cin >> a[1][i] >> a[2][i] >> a[3][i];
            if (a[1][i] != 0) flag1 = 1;
            if (a[2][i] != 0) flag2 = 1;
            if (a[3][i] != 0) flag3 = 1;
        }
        if (flag1 && !flag2 && !flag3){
            sort(a[1] + 1,a[1] + n + 1,cmp);
            for (int i = 1;i <= n / 2;i++){
                ans += a[1][i];
            }
        }
        else if (flag1 && flag2 && !flag3){
            sort(a[1] + 1,a[1] + n + 1,cmp);
            sort(a[2] + 1,a[2] + n + 1,cmp);
            for (int i = 1;i <= n / 2;i++){
                ans += a[1][i];
            }
            for (int i = 1;i <= n / 2;i++){
                ans += a[2][i];
            }
        }
        else{
            dfs(1,0,0,0,0);
        }
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}