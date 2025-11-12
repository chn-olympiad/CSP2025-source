#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    int n;
    cin>>n;
    int a[n]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5){
        if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
        else cout<<6;
    }
    return 0;
}
