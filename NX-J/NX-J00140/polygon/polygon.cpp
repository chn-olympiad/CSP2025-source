#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
long long a[maxn];
long long cnt= 0;
int n;
bool check(long long l,long long maxa,int m){
    if(l > 2*maxa && m >= 3)return true;
    else return false;
}
void dfs(int x,long long l,long long maxa,int m){
    if(x == n+1){
        if(check(l,maxa,m) == true)cnt++;
        return ;
    }
    dfs(x+1,l+a[x],max(maxa,a[x]),m+1);
    dfs(x+1,l,maxa,m);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    dfs(1,0,-1e9,0);
    cout << cnt%998244353 << '\n';
    return 0;
}
