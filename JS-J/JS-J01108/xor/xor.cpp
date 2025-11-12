#include<bits/stdc++.h>
using namespace std;
int a[500010],xo[500010],ans,n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        xo[i]=(xo[i-1]^a[i]);
    }int low=0;
    for(int i=1;i<=n;i++){
        for(int j=low;j<i;j++){
            if(j<low)continue;
            if((xo[i]^xo[j])==k){
                ans++;
                low=i;
            }
        }
    }
    cout<<ans;
    return 0;
}
