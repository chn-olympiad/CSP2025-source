#include<bits/stdc++.h>
using namespace std;
int n,m,f;
int a[310],b[310];
int c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==b[1]){
            f=i;
            break;
        }
    }
    if(f%n==0){
        c=f/n;
        if(c%2==0){
            if(f%n==0) r=1;
            else r=(n+1)-f%n;
        }
        else{
            if(f%n==0) r=n;
            else r=f%n;
        }
    }
    else{
        c=f/n+1;
        if(c%2==0){
            if(f%n==0) r=1;
            else r=(n+1)-f%n;
        }
        else{
            if(f%n==0) r=n;
            else r=f%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
