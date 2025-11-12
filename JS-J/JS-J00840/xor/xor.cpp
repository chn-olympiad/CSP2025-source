#include <bits/stdc++.h>
using namespace std;
int n,k,a[500002],b[500002],cnt1,ans,cnt0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)cnt1++;
        if(a[i]==0)cnt0++;
        b[i]=(b[i-1] xor a[i]);
    }
    if(cnt1==n){
        if(k>1){
            cout<<0<<endl;
            return 0;
        }
        if(k==1){
            cout<<n<<endl;
            return 0;
        }
        if(k==0){
            cout<<n/2<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((b[j] xor b[i-1])==k){
                i=j;
                ans++;
                continue;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
