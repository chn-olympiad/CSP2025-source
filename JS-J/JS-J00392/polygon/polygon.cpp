#include<bits/stdc++.h>
using namespace std;
int n,maxn=0,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3){
        if(a[1]+a[2]+a[3]>=2*max(a[1],max(a[2],a[3])))
            cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
        maxn=max(maxn,a[i]);
    if(maxn==1)cout<<n-2;
    return 0;
}
