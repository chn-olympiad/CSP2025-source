#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
            cin>>a[i];
    }
    int ans=a[1];
    sort(a,a+n*m+1);
    for(int i=0;i<n*m;i++){
        if(a[i]==ans) {ans=i;break;}
    }
    int x=ans/n,y=ans%n;
    if(m%2!=0){if(!(y==1||y==0)){
        if(x%2!=0)  cout<<m-x<<" "<<y;
        else if(x%2==0)   cout<<m-x<<" "<<n+1-y;
    }
    else if(y==1)   {
        if(x%2==0)  cout<<m-x<<" "<<n;
        if(x%2!=0)  cout<<m-x<<" "<<1;
    }
    else if(y==0){
        if(x%2==0)  cout<<m+1-x<<" "<<n;
        if(x%2!=0) cout<<m+1-x<<" "<<1;
    }}//1
    else if(m%2==0){
        if(!(y==1||y==0)){
        if(x%2!=0)  cout<<m-x<<" "<<y;
        else if(x%2==0)   cout<<m-x<<" "<<y;
    }
    else if(y==1)   {
        if(x%2==0)  cout<<m-x<<" "<<1;
        if(x%2!=0)  cout<<m-x<<" "<<n;
    }
    else if(y==0){
        if(x%2==0)  cout<<m+1-x<<" "<<1;
        if(x%2!=0) cout<<m+1-x<<" "<<n;
    }
    }

    return 0;
}
