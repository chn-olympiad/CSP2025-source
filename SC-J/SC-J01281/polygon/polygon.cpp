#include<bits/stdc++.h>
using namespace std;
int n,a[5010],i,c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        cout<<1;
        return 0;
    }else{
        for(i=n-2;i>=1;i--){
            c+=i;
        }
        cout<<c%998%224%353;
        return 0;
    }
}
