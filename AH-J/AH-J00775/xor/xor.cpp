#include<bits/stdc++.h>
using namespace std;
long long sum[500009],a[500009],n,k;
struct node{
    long long l,r;
};
vector<node>v;
bool cmp(node x,node y){
return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(long long l=1;l<=n;l++)
    for(long long r=l;r<=n;r++)if(sum[r]^sum[l-1]==k)v.push_back({l,r});
    sort(v.begin(),v.end(),cmp);
    long long ans=1,R=v[0].r;
    for(long long i=1;i<v.size();i++){
        if(v[i].l>R){
            ans++;
            R=v[i].r;
        }
    }
    cout<<ans;
    return 0;
}
