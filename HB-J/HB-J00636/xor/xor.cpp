#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    //30'
    if(k==0){
        int i;
        for(i=1;i<=n;i++){
            if(a[i]==0)ans++;
            if(a[i]==1 && a[i+1]==1){
                i++;
                ans++;
            }
        }
    }else{
        int i;
        for(i=1;i<=n;i++){
            if(a[i]==1)ans++;
            /*
            if(a[i]==0 && a[i+1]==0){
                i++;
                ans++;
            }
            */
        }
    }
    cout<<ans;
    return 0;
}