#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int x=a[1];
        int y=a[2];
        int z=a[3];
        if(x+y>z && y+z>x && x+z>y){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    return 0;
}
