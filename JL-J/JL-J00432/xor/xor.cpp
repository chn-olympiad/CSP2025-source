#include<bits/stdc++.h>
using namespace std;
int k;
int n,ans;
int a[500005],sum[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdin);
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=a[i]^sum[i-1];
    }
    for(int l=1;l<=n;l++){
        if(a[l]==k){
            ans++;
            continue;
        }
        for(int r=l+1;r<=n;r++){
            if((sum[r]^sum[l-1])==k){
                ans++;
                l=r;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
