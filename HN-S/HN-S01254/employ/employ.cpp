#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long mod=998244353;
long long n,m,ans,flag1=1,num,tmp,a[N],c[N],vis[N],pre[N],inv[N],cnt[N];
string s;
int qpow(long long a,int b){
    long long t=1;
    while(b){
        if(b&1)t=t*a%mod;
        b/=2,a=a%mod;
    }
    return t;
}
void init(int n){
    for(int i=1;i<=n;i++)pre[i]=(pre[i-1]*i)%mod;
    inv[n]=qpow(pre[n],mod-2);for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
void dfs(int wz,int num){
    if(wz==n+1){
        if(num<=n-m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        if(c[i]>num&&a[wz]==1)dfs(wz+1,num);
        else dfs(wz+1,num+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s,pre[0]=inv[0]=1,init(n);
    for(int i=1;i<=n;i++){
        a[i]=(int)s[i-1]-'0';
        if(a[i]==0)flag1=0;
    }
    for(int i=1;i<=n;i++)cin>>c[i],cnt[c[i]]++;
    for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
    sort(c+1,c+n+1);
    if(n<=10){
        dfs(1,0);
        cout<<ans<<"\n";
        return 0;
    }
    if(m==n){
        flag1=1;
        for(int i=1;i<=n;i++)if(a[i]==0)flag1=0;
        for(int i=1;i<=n;i++)if(c[i]==0)flag1=0;
        if(flag1)cout<<pre[n]<<"\n";
        else cout<<"0\n";
        return 0;
    }
    if(m==1){
        ans=pre[n],tmp=1,num=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                if(cnt[i-1]-i+1+num<=0)tmp=0;
                tmp=tmp*(cnt[i-1]-i+1+num)%mod;
            }
            else num++;
        }
        tmp=tmp*pre[num]%mod;
        ans=((ans-tmp)%mod+mod)%mod;
        cout<<ans<<"\n";
        return 0;
    }
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}