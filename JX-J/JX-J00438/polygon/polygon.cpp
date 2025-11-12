#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[100],b=0;
    cin>>n;
    if(n<3){
    cout<<0;
    return 0;
    }
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){if(a[i]<a[i+1]){swap(a[i],a[i+1]);}}
    if(n==3){
    if(a[1]+a[2]<a[3]+1){cout<<0;}
    else{cout<<1;}
    return 0;
    }
    if(n>=4){
    for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){if(a[i]+a[i+1]>a[j]){b++;}}
    }
    for(int i=1;i<=n;i++){
    for(int j=i+2;j<=n;j++){
    if(a[i]+a[i+1]+a[i+2]>a[j]){b++;}
    if(a[i]+a[i+1]+a[j-1]>a[j]){b++;}
    }
    }
    cout<<b;
    return 0;
    }
    return 0;
}
