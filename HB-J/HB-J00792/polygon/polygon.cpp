#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int mx=5050;
ll a[mx];
ll book[mx];
ll num[mx];
ll n;
ll ans;
ll cnt;
ll tsum;
ll tmax=-1;
//t fm(){

//
bool check(ll x,ll y){
    return x>2*y;
}
void dfs(ll in,ll x,ll sum,ll mm){
 // if(x==0){
 //     book[1]=book[2]=book[3]=1;
 //     dfs(3 ,x+3,sum+a[1]+a[2]+a[3],max(max(a[1],a[2]),a[3]));
 //     book[1]=book[2]=book[3]=0;
 // }
    if(x>=n)return ;
  if(check(sum,mm)&&x>=3){
 //     cout<<in<<" "<<x<<" "<<sum<<" "<<mm<<endl;
      ans++;
  }


 for(ll i=in;i<=n;i++){
        if(book[i]==0){
//      num[++y]=a[i];
        book[i]=1;
        dfs(i,x+1,sum+a[i],max(mm,a[i]));
        book[i]=0;
      }

  //}
}


}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        tsum+=a[i];
        tmax=max(tmax,a[i]);
  }
    if(check(tsum,tmax))ans++;
    dfs(1,0,0,0);
    cout<<ans%mod;
    return 0;
}
