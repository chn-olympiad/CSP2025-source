
#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,k,xo[500010],ans,xo2[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    xo[0]=0;
    for(int i=1;i<=n;i++) xo[i]=xo[i-1]^a[i];
    for(int i=1;i<=n;i++) xo2[i]=xo[i]^xo[i-1];
    for(int i=1;i<=n;i++) cout<<xo[i]<<" ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(xo2[j-i+1]-xo2[j-i]==k) ans++;
            else if(xo[j-i+1]==k) ans++;
        }
    }cout<<ans;
    return 0;
}

