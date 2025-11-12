#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,ans_index;
long long qz(long long l,long long r){
    long long s=0;
    for(long long i=l;i<=r;i++) s=s xor a[i];
    return s;
}
void dfs(long long l,long long r){
    if(l<1||l>n||r<1||r>n) return;
    for(long long i=r+1;i<=n;i++) dfs(i,n);
    if(qz(l,r)==k){
        ans++;
        return;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            ans=0;
            dfs(i,j);
            ans_index=max(ans_index,ans);
        }
    }
    cout<<ans_index<<endl;
    return 0;
}
