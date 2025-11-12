#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5050],ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(n==3){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                for(ll k=1;k<=n;k++){
                    if((a[i]+a[j]+a[k])>(max(a[i],max(a[j],a[k]))*2)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

