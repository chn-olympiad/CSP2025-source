#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
using namespace std;
const int MOD=998244353;
const int N=505;
int n,m;
bool dif[N];
int c[N];
bool vis[N];
int ans;
int a[N],k;
bool solve(){
    int cnt=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(cnt>=c[a[i]]||!dif[i])cnt++;
        else sum++;
    }
    if(sum>=m)return true;
    return false;
}
void dfs(int x){
    if(x==n+1){
        if(solve())ans++;
        ans%=MOD;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=true;
        a[++k]=i;
        dfs(x+1);
        --k;
        vis[i]=false;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flag=false;
    for(int i=1;i<=n;i++){
        char c;
        scanf(" %c",&c);
        if(c=='1')dif[i]=true;
        else flag=true;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
