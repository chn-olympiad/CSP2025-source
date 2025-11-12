#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+1+n*m);
    int ans;
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            ans=n*m-i+1;
        }
    }
    int a1,a2;
    if(ans%m==0){
        a1=ans/m;
    }
    else{
        a1=ans/m+1;
    }
    if(a1%2==0){
        a2=ans%m;
        if(a2==0){
            a2=m;
        }
        a2=m-a2+1;
    }
    else{
        a2=ans%m;
        if(a2==0){
            a2=m;
        }
    }
    cout<<a1<<" "<<a2;
    return 0;
}
