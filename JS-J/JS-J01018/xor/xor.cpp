#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=(1<<20)+100;
int n,m,k,a[N],sum[N],g[M],ans;
struct node{
    int l,r;
};
vector<node>v;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k) v.push_back({i,i});
        else if(g[sum[i]^k]!=0) v.push_back({g[sum[i]^k]+1,i});
        g[sum[i]]=i;
    }
    m=v.size();
    for(int i=0;i<m;){
        ans++;
        int t=i;
        while(i<m&&v[i].l<=v[t].r) i++;
    }
    cout<<ans<<"\n";
    return 0;
}
