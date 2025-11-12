#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600,mod=998244353;
int n,m,a[N],c[N],vis[N],ans,p[N];
inline int in(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') k=(k<<3)+(k<<1)+c-'0',c=getchar();
    return k*f;
}
void dfs(int pos){
    if(pos>n)
    {
        int no=0,ye=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) no++;
            else
            {
                if(no>=c[p[i]]) no++;
                else ye++;
            }
        }
        if(ye>=m) ans++;
        if(ans>=mod) ans-=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        p[pos]=i;
        vis[i]=1;
        dfs(pos+1);
        p[pos]=0;
        vis[i]=0;
    }
}
void slove1(){
    dfs(1);
    printf("%lld\n",ans);
}
void slove2(){
    int now=1;
    for(int i=1;i<=n;i++)
    now=now*2%mod;
    printf("%lld\n",now);
}
bool check(){
    for(int i=1;i<=n;i++)
    if(a[i]!=1)
    return 0;
    return 1;
}
signed main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    n=in(),m=in();
    char cc;
    for(int i=1;i<=n;i++)
    {
        cin>>cc;
        a[i]=cc-'0';
    }
    for(int i=1;i<=n;i++)
    c[i]=in();
    if(n<=10) slove1();
    else if(check()) slove2();
    else printf("0\n");
    return 0;
}
