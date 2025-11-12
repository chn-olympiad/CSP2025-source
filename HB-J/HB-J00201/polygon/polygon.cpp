#include<bits/stdc++.h>
using namespace std;
int path[1000],n,a[1000],maxn,b[1000];
long long s,ans;
bool v[1000];
void dfs(int k){
    if(k>3){
        for(int i=1;i<k;i++)s+=path[i],maxn=max(maxn,path[i]);
        if(s>2*maxn)ans++;
        ans%=998244353;
        s=0,maxn=0;
    }
    if(k>n)return ;
    for(int i=b[k-1]+1;i<=n;i++){
        if(!v[i]){
            path[k]=a[i];
            v[i]=1;
            b[k]=i;
            dfs(k+1);
            v[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(1);
    printf("%lld",ans);
    return 0;
}
