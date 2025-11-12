#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int R=a[0],ans;
    sort(a,a+n*m);
    for(int i=n*m;i>=0;i--){
        if(a[i]==R){
            ans=n*m-i;
            break;
        }
    }
    int c,r;
    if(ans%m>0){
        c=ans/m+1;
    }
    else{
        c=ans/m;
    }
    if(ans%n==0||1){
        if((ans/n)%2==1){
            r=n;
        }
        else{
            r=1;
        }
    }
    else{
        r=ans%n;
    }
    cout<<c<<" "<<r;
    return 0;
}
