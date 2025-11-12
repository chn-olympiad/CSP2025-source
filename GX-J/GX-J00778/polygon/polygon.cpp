#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sj=0,mx=-1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        sj+=a[i];
    }
    if(n<3){
        cout<<0;
    }else if(n==3){
        if(mx*2==sj){
            cout<<1;
        }
    }
    return 0;
}
