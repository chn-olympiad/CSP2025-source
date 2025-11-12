#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x,c,r,pos;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        if(a[i]==x){
            pos=n*m-i;
            break;
        }
    }
    c=pos/n;
    if(pos%n!=0){
        c++;
        r=pos%n;
    }
    else r=n;
    if(c%2==0)r=n-r+1;
    cout<<c<<" "<<r;
    return 0;
}
