#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[550],p[505],sum,ans,mod = 998224353,t,tpx[505];
char c;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>c;
        a[i] = c-'0';
        sum+=a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        if(p[i]!=0)t++;
    }
    if(sum<m){
        cout<<0;
        return 0;
    }
    if(m == n){
        if(t<n){
            cout<<0;
            return 0;
        }
        for(int i = 1;i<=n;i++){
            tpx[p[i]]++;
        }

    }
    if(sum == n){
        ans = 1;
        int aa = 1;
        for(int i = n;i>=max(aa,t);i--){
            ans = (ans*i)%mod;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
