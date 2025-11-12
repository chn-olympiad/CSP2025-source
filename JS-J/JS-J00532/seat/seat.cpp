#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[10005],cj,pm,ansn,ansm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cj=a[1];
    pm=1;
    for(ll i=2;i<=n*m;i++){
        if(a[i]>cj){
            pm++;
        }
    }
    ansm=(pm/n)+(pm%n!=0);
    if(ansm%2==0){
        pm-=(ansm-1)*n;
        ansn=n-pm+1;
    }else{
        pm-=(ansm-1)*n;
        ansn=pm;
    }
    cout<<ansm<<" "<<ansn;
    return 0;
}
