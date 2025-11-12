#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2&&k==0){
        cout<<n/2<<endl;
        return 0;
    }
    else if(k<=1){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                else if(a[i]==1&&a[i+1]==1)ans++,i++;
            }
            cout<<ans<<endl;
            return 0;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
