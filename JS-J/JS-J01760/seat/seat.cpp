#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n=0,m=0,cun=0,ji[150],lie[150],han[150];

bool cmp(ll a,ll b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>ji[i];
    }
    cun=ji[1];
    sort(ji+1,ji+1+(n*m),cmp);
    lie[0]=1;han[0]=0;
    for(ll i=1;i<=n*m;i++){
        lie[i]=ceil((i*1.0)/(n*1.0));
        if(lie[i]!=lie[i-1]){
            han[i]=han[i-1];
        }
        else{
            han[i]=han[i-1]+(lie[i]%2LL ? 1 : -1);
        }
        if(ji[i]==cun){
            cout<<lie[i]<<" "<<han[i];
        }
    }
    return 0;
}
