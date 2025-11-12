#include <bits/stdc++.h>
using namespace std;
const int N = 505;
using ill = long long;
const ill mod = 998244353ll;
int n,m;
int c[N];
bool book[N];
string s;
//n <= 10
namespace solve1{

ill ans;
int b[15];
bool flag[15];
void dfs(int x){
    if(x == n+1){
        int cnt = 0;
        for(int i=1;i<=n;i++)
            if(book[i] && (i-1 - cnt) < c[b[i]])
                cnt++;
        if(cnt >= m){
            ans++;
            ans %= mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(flag[i])
            continue;
        flag[i] = true;
        b[x] = i;
        dfs(x+1);
        flag[i] = false;
    }
    return;
}
void solve(){
    dfs(1);
    printf("%lld\n",ans);
}

}
//all book == 1
namespace solve2{

bool check(){
    for(int i=1;i<=n;i++)
        if(!book[i])
            return false;
    return true;
}
ill ans;
ill fac(ill x){
    ill res = 1ll;
    while(x){
        res = res * x%mod;
        x--;
    }
    return res;
}
void solve(){
    int k = 0;
    for(int i=1;i<=n;i++)
        k += (c[i] == 0);
    if(k == 0){
        ans = fac(n);
    }
    printf("%lld\n",ans);
}

}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin >> s;
    for(int i=1;i<=n;i++)
        book[i] = (s[i-1] == '1');
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    if(n <= 10)
        solve1::solve();
    else if(solve2::check())
        solve2::solve();
    return 0;
}
