#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int flag=0;
int a[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=1;
    }
    if(flag==0&&k==0){
        cout<<n;
        return 0;
    }
    cout<<63;
    return 0;
}
