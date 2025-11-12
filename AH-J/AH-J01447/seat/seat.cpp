#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll dlt[2]={1,-1};
ll a[10005];
bool cmp(const ll &x,const ll &y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ll n,m,fx=0;
    cin>>n>>m;
    ll t;
    cin>>a[1];
    t=a[1];
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    ll x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            cout<<x<<" "<<y;
            return 0;
        }
        if((y==n &&fx==0 )  || (y==1 && fx==1)){
            x++;
            fx=1-fx;
        }
        else y+=dlt[fx];
    }
    return 0;
}
