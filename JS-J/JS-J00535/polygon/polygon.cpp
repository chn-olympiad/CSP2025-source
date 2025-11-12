#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
unordered_map<int,ll>f[5005];
int n,a[5005];
int dfs(int now,int val){
    if(now>n)   return 0;
    if(!f[now][val])   f[now][val]=(dfs(now+1,val+a[now])+dfs(now+1,val)+(val>a[now]))%mod;
    return f[now][val];
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)   cin >> a[i];
    sort(a+1,a+n+1);
    cout << dfs(1,0);
    return 0;
}
