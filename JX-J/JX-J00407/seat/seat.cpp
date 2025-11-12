#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int c,r;
int ans;
int t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==ans){
            t=n*m-i+1;
        }
    }
    if(t<=n){
        r=t;
    }else if(t>n&&t%n!=0){
        r=t%n;
    }else if(t%n==0){
        r=n;
    }
    for(int i=1;i<=m;i++){
        if(t>i*n-n&&t<=i*n){
            c=i;
            break;
        }
    }
    if(c%2==0){
        cout<<c<<" "<<n-r+1;
    }else{
        cout<<c<<" "<<r;
    }
    return 0;
}
