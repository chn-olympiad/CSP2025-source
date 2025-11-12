#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,a[500005],dp[500005];
struct A{
    int l,r;
};
bool cmp(A a,A b){
    if(a.l==b.l) return a.r<b.r;
    else return a.l<b.l;
}
vector<A> opt;
int dfs(A u,int i){
    int maxn=0;
    for(int j=i+1;j<=opt.size();j++){
        if(opt[j].l>u.r){
            if(dp[j]) maxn=max(maxn,dp[j]);
            else maxn=max(maxn,dfs(opt[j],j));
        }
    }
    dp[i]=maxn+1;
    return dp[i];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
            int num=0;
        for(int j=i;j<=n;j++){
            num^=a[j];
            if(num==k){
                opt.push_back((A){i,j});
            }
        }
    }
    sort(opt.begin(),opt.end(),cmp);
    int maxn=0;
    for(int i=1;i<=opt.size();i++){
        if(dp[i]) maxn=max(maxn,dp[i]);
        else maxn=max(maxn,dfs(opt[i],i));
    }
    cout<<maxn;
}
