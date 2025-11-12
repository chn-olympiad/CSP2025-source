#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e2+5;
ll n,m,a[N],t,p,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
        if(a[i]==t){
            p=n*m-i+1;
            break;
        }
//    for(int i=1;i<=n*m;i++) cout<<a[i]<<' ';
//    cout<<p<<' '<<t<<"\n";
    x=p/n;
    y=p%n;
    if(y==0){
        cout<<x<<' ';
        if(x%2==1) cout<<n;
        else cout<<1;
    }else{
        cout<<x+1<<' ';
        if((x+1)%2==1) cout<<y;
        else cout<<n-y+1;
    }
    return 0;
}
/*
2 2
99 100 97 98
*/
