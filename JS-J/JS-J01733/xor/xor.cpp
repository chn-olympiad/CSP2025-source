#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
};
bool cmp(node x,node y){
    if(x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}
int a[500020],xo[500020];
vector<node> lr;
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    node v;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],xo[i]=xo[i-1]^a[i];
    lr.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((xo[i]^xo[j-1])==k){
                v.l=j;
                v.r=i;
                lr.push_back(v);
            }
        }
    }
    sort(lr.begin(),lr.end(),cmp);
    int r=0,ans=0;
    for(int i=0;i<lr.size();i++){
        // cout<<r<<" "<<lr[i].l<<endl;
        if(r<lr[i].l){
            ans++;
            r=lr[i].r;
        }
    }
    // for(int i=0;i<lr.size();i++){
    //     cout<<lr[i].l<<" "<<lr[i].r<<" "<<xo[lr[i].l-1]<<" "<<xo[lr[i].r]<<" "<<(xo[lr[i].r]^xo[lr[i].l-1])<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}
/*
4 0
2 1 0 3*/