#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000005],ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1,t;
    while(r<=n&&l<=n){
        t=a[l];
        for(int i=l+1;i<=r;i++){
            t=t^a[i];
        }
        if(t==k){
            l=r+1;
            r++;
            ans++;
        }else{
            r++;
        }
    }
    cout<<ans;
    return 0;
}
