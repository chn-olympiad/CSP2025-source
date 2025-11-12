#include <bits/stdc++.h>
using namespace std;
const int M = 1e4;
int n;
int a[M],bl[M];

int cnt = 0,add = 0,mx = 0;
void dfs(int f,int fn){
    if(f > n){
        return;
    }
    for (int i = fn;i < n;++ i){
        add += a[i];
        int mx0 = mx;
        mx = max(mx,a[i]);
        if(f >= 3){
            if (add > 2 * mx){
                ++ cnt;
            }
        };
        dfs(++ f,i + 1);
        add -= a[i];
        mx = mx0;
    }
    return;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 0;i < n;++ i){
        cin >> a[i];
    }
    dfs(1,0);
    cout << cnt % 998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
