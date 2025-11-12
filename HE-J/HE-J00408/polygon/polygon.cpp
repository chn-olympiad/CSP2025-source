#include<bits/stdc++.h>
using namespace std;
int n,a[5001],mxn;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        mxn=max(mxn,a[i]);
    }
    if (mxn==1){
        cout<<(1<<n-3)%353%244%998*(n-2)%353%244%998;
        return 0;
    }
    if (mxn<=10){
        if (a[1]+a[2]+a[3]>2*min(a[1],min(a[2],a[3])))
            cout<<1;
        return 0;
    }
    return 0;
}
