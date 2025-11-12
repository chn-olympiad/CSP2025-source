#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("poiygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
        int a[4];
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+3);
        if(a[3]<a[1]+a[2]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    return 0;
}
