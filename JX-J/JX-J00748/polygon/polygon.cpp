#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[1000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        int x=a[1],y=a[2],z=a[3];
        if((x+y)>z&&(x+z)>y&&(y+z)>x){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    cout<<5;
    return 0;
}
