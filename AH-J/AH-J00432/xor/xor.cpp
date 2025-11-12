#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,x,y,a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=2&&k==0){
        if(n==1){
            cin>>x;
            if(x==k)cout<<1;
            else cout<<0;
            return 0;
        }
        if(n==2){
            cin>>x>>y;
            if(x==k&&y==k)cout<<2;
            if(x^y==k)cout<<1;
            else cout<<0;
            return 0;

        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            a[i]=-1;
        }
    }
    ll sum=a[1],s=2;
    if(sum==-1){
        ans++;
        s=3;
        sum=a[2];
    }
    for(ll i=s;i<=n;i++){
        if(a[i]==-1){
            ans++;
            sum=a[i+1];
            i++;
        }
        else sum^=a[i];
        if(sum==k){
            ans++;
            sum=a[i+1];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
