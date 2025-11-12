#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans,sum,cnt,c;
int a[5005];
void dfs(int x) {
    while(x<n) {
        c++;
        ans+=a[x];
        cnt=a[x];
        if(ans>cnt*2 && c>=3) {
            sum++;
        }
        dfs(++x);
    }
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1);
    cout<<sum%MOD;
    return 0;
}
