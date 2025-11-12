#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define repr(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=(int)(1e6+7);
ll a[maxn];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ll n,m;cin>>n>>m;
    rep(i,1,n*m)cin>>a[i];

    ll r_score=a[1];

    sort(a+1,a+n*m+1,[](ll a,ll b){
         return a>b;
    });

    ll rank=1;

    rep(i,1,n*m)if(a[i]==r_score)rank=i;

    //cout<<rank<<endl;

    ll x,y;
    y=(rank%n==0?rank/n:rank/n+1);
    if(y%2==1)x=(rank%n==0?n:rank%n);
    else x=(rank%n==0?1:n+1-rank%n);

    cout<<y<<" "<<x<<endl;


    return 0;
}
