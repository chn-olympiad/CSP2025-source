#include<bits/stdc++.h>
using namespace std;
long long a[110],m,n,x,pos,l,r;
long long Find(long long a[],long long x){
    int i=1;
    while(a[i]!=x)
        i++;
    return i;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+1+m*n);
    pos=n*m-Find(a,x)+1;
    l=(pos+n-1)/n;
    if(l%2==1){
       if(pos%n==0) r=n;
        else r=pos%n;
    }
    else if(l%2==0){
        if(pos%n==0) r=1;
        else{
            r=pos%n;
            r=n+1-r;
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}
