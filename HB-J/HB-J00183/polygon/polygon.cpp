#include<bits/stdc++.h>
using namespace std;
#define INT long long
INT n;
INT a[5010];
INT s[5010];
INT ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(INT i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(INT i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
    }
    for(INT i=1;i<=n;++i){
        for(INT j=1;j<=i;++j){
            if(s[i]-s[j-1]>2*a[i]){
                ans=(ans+1)%998244353;
            }
        }
    }
    cout<<ans;
    return 0;
}
