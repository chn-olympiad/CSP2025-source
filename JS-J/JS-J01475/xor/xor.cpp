#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[1000006],cnt1=0,cnt0=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==1)cnt1++;
        else cnt0++;
    }
    if(k==1)cout<<cnt1;
    else cout<<cnt0;
    return 0;
}
