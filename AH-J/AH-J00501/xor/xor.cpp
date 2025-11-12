#include<iostream>
#include<cstdio>
#include<algorithm>
//define bits/stdc++.h
#define ll long long
using namespace std;
ll n,k,a[500005];
ll s[500005];
struct node{
    ll l,r;
}d[500005];
bool cmp(node x,node y){
    if(x.r!=y.r){
        return x.r<y.r;
    }
    return x.l>y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=a[i]^s[i-1];
    }
    ll nn=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((s[j]^s[i-1])==k){
                d[++nn].l=i;
                d[nn].r=j;
            }
        }
    }
//    cout<<nn<<" ";
    sort(d+1,d+1+nn,cmp);
    ll tmp=0,ans=0;
    for(int i=1;i<=nn;i++){
        if(tmp<d[i].l){
            ans++;
            tmp=d[i].r;
        }
    }
    printf("%lld",ans);
    return 0;
}
