#include <bits/stdc++.h>
using namespace std;
int n;
#define ll long long
ll a[5050];
ll ans = 0;
/*

bool b[5050];


void dfs(ll pre,ll maxn,ll sum,ll cnt,int dep){
    //cout << pre << " "<< maxn << " " << sum <<" " << cnt << " " << dep << "\n";
    if(dep > n)return;
    if(sum > 2 * maxn && cnt >= 3)
    {
        cout << "pre="<< pre << " maxn="<< maxn << " sum=" << sum <<" cnt=" << cnt << " dep=" << dep << "\n";
        ans ++;
    }

    for(int i = pre + 1;i <= n;i ++)
    {
        if(!b[i]){
            b[i] = true;
            dfs(i, max(maxn, a[i]), sum + a[i],cnt + 1,dep + 1);
            b[i] = false;
        }
        dfs(pre, maxn, sum, cnt,dep + 1);
    }
}*/
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    bool flag = true;
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if(a[i] != 1)flag=false;
    }
    if(n < 3){
        cout << 0;
        return 0;
    }

    if(n == 3){
        if(a[1] + a[2] + a[3] > 2 * max(max(a[1], a[2]), a[3]))
            ans = 1;
    }
    if(flag){
        for(int i = 1;i <= n - 2;i ++)
        {
            ans += i;
        }
    }
    /*dfs(0,0,0,0, 1);*/
    ans = ans % 998244353;
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
