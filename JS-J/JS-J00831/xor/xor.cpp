#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool pf1=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[1]){
            pf1=0;
            break;
        }
    }
    if(pf1==1){
        cout<<0;
        return 0;
    }
    bool pf2=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=0&&a[i]!=1){
            pf2=0;
            break;
        }
    }
    if(pf2){
        if(k>1){
            cout<<0;
            return 0;
        }
        int ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else{
                    if(a[i+1]==1){
                        ans++;
                        i++;
                    }
                }
            }
            cout<<ans;
            return 0;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
