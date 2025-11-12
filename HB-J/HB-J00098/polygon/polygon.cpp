#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5005];
int g[5005];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    if(n==3){
        int x,y,z;
        cin >> x >> y >> z;
        if(x+y+z>(2*(max(max(x,y),z)))){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        g[i]=g[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(g[i]-g[j]>a[i]){
                ans++;
            }
            ans=(ans+mod)%mod;
        }
    }
    cout << ans;
    return 0;
}
