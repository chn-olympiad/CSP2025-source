#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int ap=a[i-1]^a[j];
            if(ap==k){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
