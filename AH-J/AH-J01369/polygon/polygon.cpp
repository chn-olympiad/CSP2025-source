#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[25],cnt=0;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            for(ll z=j+1;z<=n;z++){
                if(a[j]+a[z]>a[i]||a[i]+a[j]>a[z]||a[i]+a[z]>a[j]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
