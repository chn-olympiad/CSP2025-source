#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}a[500005];
int n,k,sum,cnt,f[500005];
vector<int> g[500005];
bool cmp(node x,node y){
    if(x.r!=y.r)return x.r<y.r;
    return x.l>y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    g[k].push_back(0);
    for(int i=1,x;i<=n;i++){
        cin>>x;
        sum^=x;
        f[i]=sum;
        for(int j=0;j<g[sum].size();j++){
            a[++cnt]={g[sum][j]+1,i};
        }
        g[sum].clear();
        g[k^sum].push_back(i);
    }
    sort(a+1,a+1+cnt,cmp);
    int ans=0,ed=0;
    for(int i=1;i<=cnt;i++){
        if(a[i].l>ed){
            ans++;
            ed=a[i].r;
        }
    }
    cout<<ans;
    return 0;
}
