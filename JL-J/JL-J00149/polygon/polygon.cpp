#include<bits/stdc++.h>
using namespace std;
long long a[5010],ans=0,n,s[5010];
bool isms(long long cur){
    long long summ=0,maxx=0;
    for(long long i=1;i<=cur;i++){
        summ+=a[s[i]];
        maxx=max(maxx,a[s[i]]);
    }
    return summ>(maxx*2);
}
void dfs(long long cur,long long k){
    for(long long i=k;i<=n;i++){
        s[cur]=i;
        if(cur>=3&&isms(cur)){
            ans++;
        }
        if(cur<n){
            dfs(cur+1,i+1);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
