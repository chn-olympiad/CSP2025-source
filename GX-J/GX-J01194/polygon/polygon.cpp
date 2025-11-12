#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon","r",stdin);
    freopen("polygon","w",stdout);
    int n;
    cin>>n;
    int a[n],zd;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    zd=max(a[0],max(a[1],a[2]));
    if(a[0]+a[1]+a[2]>zd*2){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
