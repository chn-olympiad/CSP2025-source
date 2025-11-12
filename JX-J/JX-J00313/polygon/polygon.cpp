#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,ans,s[10010],s1[10010];
void dfs(int q,int x,int a,int e,int r){
    if(x>=r)return;
    if(a==1)q=q+s[x];
    if(q>=e)ans++;
    dfs(q,x+1,1,e,r);
    dfs(q,x+1,0,e,r);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&a);
    for(int i=0;i<a;i++){
        scanf("%lld",&s[i]);
    }
    sort(s+0,s+a);
    for(int i=a-1;i>=0;i--){
        dfs(0,0,1,s[i],i);
        //dfs(0,0,0,s[i],i);
    }
    printf("%lld",ans);
    return 1;
}
