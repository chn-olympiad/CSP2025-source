#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool v=true;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)if(a[i]!=1)v=false;
    if(v)cout<<n/2;
    else {
        sort(a+1,a+n+1);
        int j=n;
        if(k==1){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            cout<<ans;
            }
        }
        else {
            int ans=0;
            int j=n;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                    j--;
                }
            }
            cout<<ans+j/2;
        }
    }
    return 0;
}
