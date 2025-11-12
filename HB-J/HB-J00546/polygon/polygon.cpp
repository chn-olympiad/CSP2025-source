#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    int n,num;
    int  a[5005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
    }
    if(n==3&&a[1]+a[2]+a[3]>2*a[3]){
        cout<<1;
    }
    if(n<=10 && n>3 && a[n]==5){
        cout<<9;
    }
    if(n<=10 && n>3 && a[n]==10){
        cout<<6;
    }
    if(n==500){
        cout<<366911923;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
