#include <bits/stdc++.h>

using namespace std;

int n,k,a[500005];
int sum[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int ta=1,tb=1;
    int cnt1=0,cnt0=0,cnt11=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt0++;
        if(a[i]==1&&a[i-1]==1&&a[i-2]!=1) cnt11++;
        if(a[i]>1) tb=0;
        if(a[i]=0) ta=0;
    }
    if(ta){
        cout<<n/2;
    }else if(tb){
        if(k=1)
            cout<<cnt1;
        else if(k=0)
            cout<<cnt0+cnt11;
    }
    return 0;
}
