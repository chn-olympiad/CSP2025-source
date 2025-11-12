#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k) ans++;
    }
    for(int i=1;i<n;i++){
        long long result=a[i];
        for(int j=i+1;j<=n;j++){
            result^=a[j];
            if(result==k) ans++;
        }
    }
    cout<<ans;
    return 0;
}
