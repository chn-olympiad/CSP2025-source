#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[1005];
ll mb;
bool cmp(ll q,ll y){
    return q>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    mb=a[1];
    sort(a+1,a+1+n*m,cmp);
    ll x;
    for(ll i=1;i<=n*m;i++){
        if(a[i]==mb){
            x=i;
            break;
        }
    }
    ll ls=ceil(x*1.0/n);
    x%=n;
    if(x==0){
        x=n;
    }
    if(ls%2){
        printf("%lld %lld",ls,x);
    }else{
        printf("%lld %lld",ls,n-x+1);
    }
    return 0;
}
//rp++
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
