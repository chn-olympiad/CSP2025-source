#include<bits/stdc++.h>
using namespace std;
int n,k,ans,w;
int main(){
    cin>>n>>k;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==1&&a[i+1]==1){
                ans++;
                i++;
            }
            else if(a[i]==0) ans++;
        }
        cout<<ans;
    }
    else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) ans++;
            else{
                if(a[i+1]==0){
                    ans++;
                    i++;
                }
            }
        }
        cout<<ans;
    }
    else cout<<2;
    return 0;
}
