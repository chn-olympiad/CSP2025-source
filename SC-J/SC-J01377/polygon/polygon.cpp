#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ma,s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
        ma=max(a[i],ma);
    }
    if(s>ma*2)cout<<"1";
    else cout<<"0";
    return 0;
}