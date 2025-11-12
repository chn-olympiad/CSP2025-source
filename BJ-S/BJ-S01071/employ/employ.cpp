#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}string s;
const int N=2e5+5,mod=998244353;
int c[N],sum,a[N],flag[N],n,m;
void dfs(int x){
    if(x==n+1){
        int d=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){d++;continue;}
            if(d>=c[a[i]]){d++;continue;}cnt++;
        }if(cnt>=m)sum++;return ;
    }
    for(int i=1;i<=n;i++){
        if(flag[i])continue;
        flag[i]=1;a[x]=i;dfs(x+1);
        flag[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s;bool flag=1;
    for(int i=1;i<=n;i++)c[i]=read();
    if(n>20){
        int cnt=n,ans=1;
        for(int i=1;i<=n;i++)if(c[i]==0)cnt--;
        for(int i=1;i<=cnt;i++)ans=(ans*i)%mod;
        cout<<ans%mod;return 0;
    }dfs(1);cout<<sum%mod;
    return 0;
}