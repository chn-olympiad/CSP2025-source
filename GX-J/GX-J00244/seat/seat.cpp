#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll a,ll b){
return a>b;}
int main(){
 //   freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    ll a[1000001];
    ll n,m;cin>>n>>m;
    cin>>a[1];
    ll z=a[1];
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,cmp);
    int cnt;
    for(int i=1;i<=n*m;i++){
        if(a[i]==z) cnt=i;
    }
    //cout<<cnt<<"\n";
    ll x,y;
    if(cnt%m==0) x=cnt/m;
    else x=cnt/m+1;
    if(x%2!=0){
        if(cnt%m==0) y=m;
        else y=cnt%m;
    }else{
        if(cnt%m==0) y=1;
        else y=m-cnt%m+1;
    }
    cout<<x<<' '<<y;
    return 0;
}
