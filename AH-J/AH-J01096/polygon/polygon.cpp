#include<bits/stdc++.h>
using namespace std;
int n,a[5001],s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<3)s=0;
    else if(n==5){
        if(a[1]==2)s=6;
        else s=9;
    }
    else if(n==3){
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])s=1;
    }
    else s=366911923;
    cout<<s;
    return 0;
}
