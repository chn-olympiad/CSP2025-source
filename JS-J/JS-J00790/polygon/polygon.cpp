#include <bits/stdc++.h>
using namespace std;

void read(int &x){
    x=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    x*=f;
}
const int N=1e5+10;
const int mod=998244353;
int n;
int a[N],cnt;
int vis[N];

void dfs(int x,int sum,int maxn){
    if(sum>maxn*2){
        cnt=(cnt+1)%mod;
    }
    for(int i=x+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,sum+a[i],max(maxn,a[i]));
            vis[i]=0;
        }
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        vis[i]=1;
        dfs(i,a[i],a[i]);
    }
    cout<<cnt%mod;
    return 0;
}
