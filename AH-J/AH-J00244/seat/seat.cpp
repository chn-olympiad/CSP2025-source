#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int cnt;
int c,r;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==cnt){
            ans=n*m-i+1;
            break;
        }
    }
    if(ans%n==0){
        c=ans/n;
    }
    else{
        c=ans/n+1;
    }
    if(c%2!=0){
        if(ans%n!=0){
            r=ans%n;
        }
        else{
            r=n;
        }
    }
    else{
        if(ans%n!=0){
            r=n-(ans%n)+1;
        }
        else{
            r=1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
