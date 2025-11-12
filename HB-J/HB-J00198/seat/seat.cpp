#include<bits/stdc++.h>
using namespace std;
long long n,m,a,x,mx=0,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i=1;i<n*m;i++){
        cin>>a;
        if(a>x)mx++;
    }
    mx+=1;
    if(n==1){
        c=mx,r=1;
        cout<<c<<" "<<r;
        return 0;
    }
    if(m==1){
        c=1,r=mx;
        cout<<c<<" "<<r;
        return 0;
    }
    c=mx/n+1;
    if(mx%n==0){
        c--;
    }
    if(c%2==0){
        r=n-(mx+n-n*c)+1;
    }
    else{
        r=mx+n-n*c;
    }
    cout<<c<<" "<<r;
    return 0;
}