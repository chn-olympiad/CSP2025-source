#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum[i]=sum[i]^a[j];
        }
        if(sum[i]==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
