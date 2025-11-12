#include<bits/stdc++.h>
using namespace std;
int x,a[110],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    a[1]=x;
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+1+n*m);
    int pos=lower_bound(a+1,a+1+n*m,x)-a;
    pos=n*m-pos+1;
    if(pos%n==0){
        x=pos/n;
        pos%=n;
    }
    else{
        x=pos/n+1;
        pos%=n;
    }
    cout<<x<<" ";
    if(pos==0){
        if(x%2==1) cout<<n;
        else cout<<1;
    }
    else{
        if(x%2==1) cout<<pos;
        else cout<<n-pos+1;
    }
    return 0;
}
