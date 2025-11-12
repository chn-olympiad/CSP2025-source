#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],c[500005],t=0,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=(c[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=t;j<i;j++){
            if((c[i]^c[j])==k){
                ans++;
                t=i;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
