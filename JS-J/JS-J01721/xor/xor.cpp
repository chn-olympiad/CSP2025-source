#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=(long long)(s[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((long long)(s[j]^s[i-1])==k){
                ans++;
                i=j+1;
                continue;
            }
        }
    }
    cout<<ans;
}
