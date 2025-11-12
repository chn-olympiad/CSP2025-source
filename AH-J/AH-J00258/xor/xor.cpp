#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],sum[500010],f;
struct stu{
    ll l,r;
}s[1000010];
bool cmp(const stu &x,const stu &y){
    return x.r<y.r;
}
bool check(ll l,ll r){
    ll z=sum[r]^sum[l-1];
    return z==k;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        if(a[i]!=1) f=1;
    }
    if(!f){
        cout<<n/2;
    }
    else{
        ll tot=0;
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                if(check(l,r)){
                    ++tot;
                    s[tot].l=l;
                    s[tot].r=r;
                }
            }
        }
        sort(s+1,s+tot+1,cmp);
        ll ans=0,R=s[1].r;
        if(check(s[1].l,s[1].r)) ans++;
        for(int i=2;i<=tot;i++){
            if(s[i].l>R){
                ans++;
                R=s[i].r;
            }
        }
        cout<<ans;
    }
    return 0;
}
