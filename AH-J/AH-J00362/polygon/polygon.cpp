#include<bits/stdc++.h>
using namespace std;
int n;
long long a[114514];
long long ans;
long long N=998244353;
void dfs(long long i,long long sum,long long maxn,long long cnt){
    if(i==n+1){
        if(sum>2*maxn&&cnt>=3){
            ans++;
            ans=ans%N;
        }
        return;
    }
    dfs(i+1,sum,maxn,cnt);
    dfs(i+1,sum+=a[i],max(maxn,a[i]),cnt+=1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
