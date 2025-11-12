
#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a[1000100],f[1000100],sum,l;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1) sum++;
        if(k==0){
            if(sum%2==0){
                ans++;
                sum=0;
            }
        }else{
            if(sum%2==1){
                ans++;
                sum=0;
            }
        }

    }
    cout<<ans;
    return 0;
}
