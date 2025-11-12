#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(ans>2*maxn){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
