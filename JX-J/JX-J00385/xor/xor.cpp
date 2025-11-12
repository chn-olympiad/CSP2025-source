#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[500005],cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)cnt1++;
        if(a[i]==0)cnt0++;
    }
    if(k==1){
        cout<<cnt1;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==1&&a[i+1]==1)cnt++,i++;
    }
    cout<<cnt0+cnt;
    return 0;
}

// 011011001111000111001
// 0 11 0 11 0 0 11 11 0 0 0 11 0 0
//
