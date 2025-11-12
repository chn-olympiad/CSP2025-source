#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        if(sum[i]==k){
            ans++;
            for(int j=i+1;j<=n;j++){
                sum[j]^=sum[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
