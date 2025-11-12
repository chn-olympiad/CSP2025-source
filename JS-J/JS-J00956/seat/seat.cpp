#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b,sum,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a;
    for(ll i=2;i<=m*n;i++){
        cin>>b;
        if(b>a) sum++;
    }
    sum++;
    c=ceil(1.0*sum/n);
    cout<<c<<' ';
    if(c%2==0){
        if(sum%n==0) cout<<1;
        else cout<<n-sum%n+1;
    }
    else{
        if(sum%n==0) cout<<n;
        else cout<<sum%n;
    }
    return 0;
}
