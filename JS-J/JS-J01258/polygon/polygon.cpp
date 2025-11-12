#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int sum=0,mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    int ans=0;
    if(n==3){
        if(sum>2*mx) cout<<1;
    }else{
        int s=0,t=6;
        for(int i=3;i<=n;i++){
            for(int j=i;j<=n;j++){
                s=s*j%998244353;
            }
            ans+=s/t;
            ans%=998244353;
            s=0;
            t*=(t+1);
        }
        cout<<ans;
    }
    return 0;
}