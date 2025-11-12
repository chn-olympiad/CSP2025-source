#include<bits/stdc++.h>
namespace test{
    std::string s;
    int flag;
    long long ans=1;
    constexpr long long mod=998244353;
    constexpr int N=10005;
    long long a[N],vis[N];
    int n,m;
    void dfs(int step){
        if(step>m){++ans;return;}
        for(int i=1;i<=n;++i){
            if(!vis[i]){
                vis[i]=true;
                dfs(step+1);
                vis[i]=false;
            }
        }
    }
    void main(){
        freopen("employ.in","r",stdin);
        freopen("employ.out","w",stdout);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin>>n>>m;
        std::cin>>s;
        int len=s.size();
        for(int i=0;i<len;++i)if(s[i]=='0')flag=1;
        for(int i=1;i<=n;++i)std::cin>>a[i];
        if(!flag){
            for(int i=1;i<=n;++i)ans*=i,ans%=mod;
            std::cout<<ans;
        }else if(m==1){
            int pos=s.find("1");
            if(static_cast<size_t>(pos)==std::string::npos){std::cout<<"0\n";return;}
            std::sort(a+1,a+n+1);
            int pos1=std::lower_bound(a+1,a+n+1,pos)-a;
            for(int i=1;i<=n-pos1+1;++i)ans=ans*i%mod;
            std::cout<<ans<<'\n';
        }else if(m==n){
            std::sort(a+1,a+n+1);
            if(flag)std::cout<<0;
            else{
                for(int i=1;i<=n;++i)ans=ans*i%mod;
                std::cout<<ans<<'\n';
            }
        }
        else if(n<=18){
            ans=0;dfs(1);
            std::cout<<ans<<'\n';
        }
        else{
            int cnt=0;
            ans=0;for(int i=0;i<len;++i)if(s[i]=='1')cnt++;
            if(m>cnt)std::cout<<"0\n";
        }
    }
}
int main(){test::main();return 0;}
