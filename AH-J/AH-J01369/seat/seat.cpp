#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5;
ll n,m,a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    ll k=n*m;
    for(ll i=1;i<=k;i++){
        cin>>a[i];
    }
    ll s=a[1];
    ll p=0;
    sort(a+1,a+k+1);
    for(ll i=k;i>=1;i--){
        if(a[i]==s){
            p=k-i+1;
            break;
        }
    }
    if(p%m==0){
        cout<<p/m<<" ";
    }else{
        cout<<p/m+1<<" ";
    }
    if((p/m)%2!=0&&n%p!=0){
        if(p%m==0){
            cout<<"1";
        }else{
            cout<<m-(p%m)+1;
        }
    }else{
        if(p%m==0){
            cout<<m;
        }else{
            cout<<p%m;
        }
    }
    return 0;
}
