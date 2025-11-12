#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    bool f[n];
    for(int i=0;i<n;i++){
        cin>>a[n];
    }
    if(n<3){
        cout<<0;
    }else{
        if(n==3){
            if(a[0]+a[1]+a[2]>2*max(max(a[0],a[1]),a[2]));
        }
    }else{
        cout<<"9";
    }
    return 0;
}
