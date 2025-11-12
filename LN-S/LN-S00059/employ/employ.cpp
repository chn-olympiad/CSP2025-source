#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n,m;
string s;
int c[550];
bool vis[550];

long long dfs(int step,int yes,int no){
    if(n-step+2+yes<m) return 0;
    if(yes>=m){
        long long res = 1;
        for(int i = 1; i<=n-step+1; ++i){
            res *= i; res %= P;
        }
        return res;
    }
    if(step>n){
        if (yes>=m) return 1;
        return 0;
    }
    long long res = 0;
    for(int i = 1; i<=n; ++i){
        if(vis[i]==true) continue;
        vis[i] = true;
        if(s[step]=='0' || no>=c[i]) res += dfs(step+1,yes,no+1), res %= P;
        else res += dfs(step+1,yes+1,no), res %= P;
        vis[i] = false;
    }
    return res;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s; s = ' '+s;
    for(int i = 1; i<=n; ++i){
        scanf("%d",&c[i]);
    }
    cout << dfs(1,0,0);
    return 0;
}
