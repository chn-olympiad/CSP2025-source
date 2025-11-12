#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int one=0,zero=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        one+=a[i];
        zero+=(!a[i]);
    }
    if(k==1)cout<<one;
    else {//k==0
        int ans=zero;
        for(int i=1;i<=n;i++){
            if(a[i]&&a[i+1]){ans++;i++;}
        }
        cout<<ans;
    }
    return 0;
}
//solve: a[i]<=1,k<=1
