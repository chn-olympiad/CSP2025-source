#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e3 + 5,p = 998244353;
int n,ans = 0;
int a[N] = {0},poly[N] = {0};
bool vis[N] = {0};

bool check(int m)
{
    int len = 0,maxx = INT_MIN;
    for (int i = 1;i <= m;i++){
        len += poly[i];
        maxx = max(maxx,poly[i]);
    }
    if (len > (maxx * 2)) return 1;
    return 0;

}

void dfs(int dep,int m,int st)
{
    if (dep > m){
        if (check(m)){
            ans++;
            ans %= p;
        }
        return ;
    }
    for (int i = st;i <= n;i++){
        if (vis[i]) continue;
        vis[i] = 1;
        poly[dep] = a[i];
        dfs(dep + 1,m,i + 1);
        vis[i] = 0;
        poly[i] = 0;
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 3;i <= n;i++){
        dfs(1,i,1);
    }
    cout << ans;
    return 0;
}