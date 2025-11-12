#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long ans=0;
void dfs(long long depth,long long sum,long long maxn,long long m){
    if(m>=3&&sum>2*maxn){
        ans++;
        ans%=998244353;
    }
    if(depth>n){
        return ;
    }
    for(int i=depth+1;i<=n;i++){
        dfs(i,sum+a[i],max(maxn,a[i]),m+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i],a[i],1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
