#include <bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long s[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>s[1];
    for(int i=2;i<=n;i++){
        cin>>s[i];
    }
    for(int i=2;i<=n;i++){
        if(s[i]==k||s[i]^s[i-1]==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
