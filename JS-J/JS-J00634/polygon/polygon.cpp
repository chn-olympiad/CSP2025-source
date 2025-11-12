#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],i,j,k,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n<=3){
        for(i=0;i<n-1;i++) sum+=a[i];
        if(sum>a[n-1]) cout<<1;
        else cout<<0;
    }
    return 0;
}
