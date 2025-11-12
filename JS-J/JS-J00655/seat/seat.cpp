#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[105];

bool cmp(ll a,ll b){
    return a>b;
}

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    ll x=a[1],pos;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(x==a[i]){
            pos=i;
            break;
        }
    }
    //cout<<pos<<endl;
    if(pos==1)cout<<"1 1";
    else{
    ll ansy=(pos-1)/n+1;
    ll ansx=0;
    if(ansy%2==1){
        ansx=(pos-1)%n+1;
    }else{
        ansx=(pos-1)%n+1;
        ansx=n+1-ansx;
    }
    cout<<ansy<<' '<<ansx;
    }
    return 0;
}

