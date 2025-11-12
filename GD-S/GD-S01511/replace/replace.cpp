#include<bits/stdc++.h>
#define ll long long 
#define ep emplace
#define fi first
#define se second 
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int N=5e5+10,mod=998244353;
bool st;
int n,q,fa[N][20],sz[N],len[N],ch[N][676],idx=1,id[1010],top=0,vis[1010];
char s1[N],s2[N];
bool ed;
int get(int a,int b){
    a-='a',b-='a';
    return a*26+b;
}
void misaka(){
    n=read(),q=read();
    rep(i,1,n){
        scanf("%s%s",s1+1,s2+1);
        int p=1,m=strlen(s1+1);
        rep(j,1,m){
            int c=get(s1[j],s2[j]);
            if(!vis[c]){
                vis[c]=1;
                id[c]=top++;
            }
            int &v=ch[p][id[c]];
            if(!v) v=++idx;
            len[v]=len[p]+1;
            p=v; 
        }
        sz[p]++;
    }
    top--;
    queue<int> Q;
    rep(i,0,top){
        int &v=ch[1][i];
        if(v) Q.ep(v),fa[v][0]=1;
        else v=1;
    }
    while(Q.size()){
        int u=Q.front();Q.pop();
        rep(i,0,top){
            int &v=ch[u][i],f=fa[u][0];
            if(!v) v=ch[f][i];
            else{
                fa[v][0]=ch[f][i],Q.ep(v);
                rep(j,1,19) fa[v][j]=fa[fa[v][j-1]][j-1];
                sz[v]+=sz[fa[v][0]];
            }
        }
    }
    while(q--){
        scanf("%s%s",s1+1,s2+1);
        int m=strlen(s1+1);
        if(strlen(s2+1)!=m){
            puts("0");
            continue;
        }
        int L=0,R=m+1;
        rep(i,1,m){
            if(s1[i]==s2[i]) L=i;
            else break;
        }
        per(i,m,1){
            if(s1[i]==s2[i]) R=i;
            else break;
        }
        int p=1;
        ll ans=0;
        rep(i,1,m){
            int c=get(s1[i],s2[i]);
            if(!vis[c]) p=1;
            else p=ch[p][id[c]];
            if(i>=R-1){
                if(i-len[p]>L) continue;
                int u=p;
                per(j,19,0)if(i-len[fa[u][j]]<=L) u=fa[u][j];
                ans+=sz[p]-sz[fa[u][0]];
            }
        }
        printf("%lld\n",ans);
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // printf("%lf",(&st-&ed)/1024./1024);
    int T=1;
    rep(i,1,T) misaka();
    // cerr<<'\n'<<clock();
    return 0;
}