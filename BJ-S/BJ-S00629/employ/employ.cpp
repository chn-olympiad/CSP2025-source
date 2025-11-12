#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
typedef long long ll;
const int mod=998244353;
inline ll read(){
    ll res=0,p=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')p=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+(c-'0');
        c=getchar();
    }
    return res*p;
}
struct modint{
    ll x;
    inline modint(ll x_){
        x=x_%mod;
    }
    inline modint(){x=0;}
    inline modint operator+(modint b){
        return {(x+b.x)%mod};
    }
    inline modint operator-(modint b){
        return {(x-b.x%mod+mod)%mod};
    }
    inline modint operator*(modint b){
        return {(x*b.x)%mod};
    }
};
inline modint qpow(modint a,ll b){
    modint res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
const int maxn=505;
char s[maxn];
bool as[maxn];
int ac[maxn],in,im;
bool vis[maxn];
modint fac[maxn],ans;
inline void dfs(int cur,int ok){
    if(cur>in){
        if(ok>=im)ans=ans+1;
        return;
    }
    if(ok>=im){
        ans=ans+fac[in-cur+1];
        return;
    }
    rep(v1,1,in)if(!vis[v1]){
        int nc=(as[cur]&&ac[v1]>cur-ok-1)+ok;
        if(in-cur+nc<im)continue;
        vis[v1]=true;
        dfs(cur+1,nc);
        vis[v1]=false;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    in=read(),im=read();
    fac[0]=1;
    rep(v1,1,in)fac[v1]=fac[v1-1]*v1;
    scanf("%s",s+1);
    rep(v1,1,in){
        ac[v1]=read();
        as[v1]=(s[v1]=='1');
    }
    if(in<=20){
        dfs(1,0);
        cout<<ans.x<<endl;
    }
    else if(im==1){
        sort(ac+1,ac+in+1);
        int cnt=0,p=0;
        ans=1;
        rep(v1,1,in)if(as[v1]){
            while(ac[p+1]<=v1-1&&p<in)p++;
            if(cnt>=p){
                ans=0;
                break;
            }
            modint tt=p-cnt;
            ans=ans*tt;
            cnt++;
        }
        cout<<(fac[in]-ans*fac[in-cnt]).x<<endl;
    }
    else if(im==in){
        bool flag=true;
        rep(v1,1,in)flag&=as[v1];
        cout<<(flag?fac[in].x:0)<<endl;
    }
    return 0;
}