#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int used[5010];
long long ans;
void dfs(int k,int maxn,long long sum,int last){
    if(k>=3&&sum>maxn*2){
        ans++;
    }
    for(int i=last+1;i<=n;i++){
        if(used[i]==0){
            used[i]=1;
            dfs(k+1,max(maxn,a[i]),sum+a[i],i);
            used[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<(ans+998244353)%998244353;
    return 0;
}
