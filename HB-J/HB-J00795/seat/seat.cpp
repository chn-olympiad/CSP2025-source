#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m,R,a[105];
    cin>>n>>m>>R;//r wei xiaoR cheng ji
    a[1]=R;//di yi ge wei xiaoR cheng ji
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,greater<ll>());
    ll k=lower_bound(a+1,a+1+(m*n),R,greater<ll>())-a;//shi yong lower_bound lai cha zhao xiaoR
    if(k%n==0){
        cout<<k/n<<" "<<n;
    }
    else{
        cout<<k/n+1<<" ";
        if((k/n+1)%2==0) cout<<n-(k/n+1)+1;
        else cout<<k%m;
    }
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    return 0;
}
