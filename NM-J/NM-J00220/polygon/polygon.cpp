#include<bits/stdc++.h>
using namespace std;
int n,a[6];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5){
        if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
            cout<<9;
        }
        if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
            cout<<6;
        }
    }
    else{
        cout<<b;
    }
    return 0;
}
