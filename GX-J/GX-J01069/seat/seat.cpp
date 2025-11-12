#include <bits/stdc++.h>
using namespace std;
int n,m,jilu=0,ii=0,i1=0,j2=0;
int a[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    jilu=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--) {
        if(a[i]==jilu){
            ii=n*m-i+1;
            break;
        }
    }
    if(ii%n!=0)j2=ii/n+1;
    else j2=ii/n;
    if(ii%(n*2)<=n&&ii%(n*2)!=0){
        if(ii%(n*2)==n) i1=n;
        else i1=ii%n;
    }
    else{
        if(ii%(n*2)<=n+n/2&&ii%(n*2)!=0){
            ii+=(n-ii%n);
            if(ii%n!=0)i1=ii%n;
            else i1=ii/n;
        }
        else if(n%2){
            if(ii%(n*2)==n+n/2+1) i1=ii%n;
        }
        else{
            if(ii%(n*2)!=0){
                ii-=(n-ii%n);
                i1=ii%(n*2);
            }
            else i1=1;
        }
    }
    cout<<j2<<' '<<i1;
    return 0;
}
