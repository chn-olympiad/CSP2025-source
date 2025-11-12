#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],b[510],ans;
char c[510];
bool vis[510];
void DFS_(int x){
    if(x>n){
        int cnt=0;
        for(int i=1;i<=n;i++)if(c[i]=='1'&&a[b[i]]>i-1-cnt)cnt++;
        if(cnt>=m)ans++,ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        b[x]=i;
        vis[i]=1;
        DFS_(x+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    DFS_(1);
    printf("%d",ans);
    return 0;
}
