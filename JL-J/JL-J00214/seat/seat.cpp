#include<bits/stdc++.h>
using namespace std;
int n,m,s,c,r,x;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            s=n*m-i+1;
        }
    }
    if(s%n==0) c=s/n;
    if(s%n>0) c=s/n+1;
    if(c%2==1) r=s-m*(c-1);
    if(c%2==0) r=m*c-s+1;
    cout<<c<<" "<<r;
    return 0;
}
