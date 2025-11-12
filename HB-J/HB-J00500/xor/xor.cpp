#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],flag=0,cnt,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=1;
        }
    }
    if(flag==0){
        cout<<n/2;
        return 0;
    }
    else{
        cnt=a[1];
        for(int i=2;i<=n;i++){
            if(cnt==k){
                cnt=a[i];
                ans++;
                continue;
            }
            cnt^=a[i];
        }
        if(cnt==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}