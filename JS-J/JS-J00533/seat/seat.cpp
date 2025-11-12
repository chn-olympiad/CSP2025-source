#include<bits/stdc++.h>
using namespace std;
struct N{
    long ii,iii;
}a[10000];
bool xcp(N x,N y){
    return x.ii>y.ii;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long n,m;
    cin>>n>>m;
    for(long i=1;i<=n*m;i++){
        cin>>a[i].ii;
        a[i].iii=i;
    }sort(a+1,a+n*m+1,xcp);
    long pl=1;
    for(long i=1;i<=n*m;i++){
        if(a[i].iii==1){
            pl=i;
            break;
        }
    }
    long le1=ceil(pl*1.0/n);
    cout<<le1<<" ";
    if(pl%n==0){
        if(le1%2==1){
            cout<<n;
            return 0;
        }else{
            cout<<1;
            return 0;
        }
    }
    pl%=n;
    if(le1%2==1){
        cout<<pl;
        return 0;
    }else{
        cout<<n-pl+1;
        return 0;
    }
    return 0;
}
