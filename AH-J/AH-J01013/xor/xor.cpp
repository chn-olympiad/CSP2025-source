#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        s[i]=(s[i-1]^a[i]);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            if((s[j]^s[i-1])==k){
                ans++;
                i=j+1;
            }
        }
    }
    cout<<ans;
}
