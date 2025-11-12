#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=998244353;
int f[N],a[N],n,m,ans,vis[N];
string s;

inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}

inline void write(int x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline void dfs(int now,int x,int sum){
    if(now==x+1){
        if(sum==m) ans++;
        if(ans==mod) ans=0;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            f[now]=i;
            vis[i]=1;
            if(s[now]=='0'){
                if(sum!=m) dfs(now+1,x,sum+1); 
                // else cout<<"!!!";
            }
            else{
                if(a[f[i]]<=sum){
                    if(sum!=m) dfs(now+1,x,sum+1);
                }
                else dfs(now+1,x,sum);
            }
            // dfs(now+1,x);
            vis[i]=0;
        }
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s;
    s=' '+s;
    m=n-m;
    for(int i=1;i<=n;i++) a[i]=read();
    if(m==0){
        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) flag=1;
        }
        if(flag){
            puts("0");
        }
        else {
            int ans=1;
            for(int i=1;i<=n;i++) ans=ans*i%mod;
            cout<<ans<<endl;
        }
        return 0;
    }
    dfs(1,n,0);    
    cout<<ans<<endl;
    return 0;
}