#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5,M=1e6+5;
struct Node {
    LL l,r;
}a[M];
LL s[N],n,k;
LL yh[N];
bool operator <(const Node &x,const Node &y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    LL cnt0=0,cnt1=0;
    bool fa=true,fb=true;
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        yh[i]=(yh[i-1]^s[i]);
        if(s[i]!=1) fa=false;
        if(s[i]!=1&&s[i]!=0) fb=false;
    }
    if(fa){
        if(k==0) cout<<n/2;
        else cout<<n;
        return 0;
    }
    if(fb){
        for(LL i=1;i<=n;i++){
            if(s[i]==1) cnt1++;
            if(s[i]==0) cnt0++;
        }
        if(k==1){
            cout<<cnt1;
        }
    }
    LL tot=0;
    for(LL l=1;l<=n;l++){
        for(LL r=l;r<=n;r++){
            if((yh[r]^yh[l-1])==k){
                a[++tot].l=l;
                a[tot].r=r;
            }
        }
    }
    sort(a+1,a+tot+1);
    LL ans=1,R=a[1].r;
    for(LL i=2;i<=tot;i++){
        if(a[i].l>R){
            R=a[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
