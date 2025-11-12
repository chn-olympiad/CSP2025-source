#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+10;
const int maxm=5e6+10;
const int mod=998244853;
int n,m;
int len[2],base[maxm];
int f[2][maxm];
char s[2][maxm];
map<pair<int,int>,vector<int> > mp;
struct node{
    int l,r,L;
    bool is;
    int a[2],b[2];
}c[maxn];
inline void ipt(){
    base[0]=1;
    for(int i=1;i<=5e6;i++)base[i]=base[i-1]*233%mod;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s[0],s[1]);
        len[0]=strlen(s[0]);
        len[1]=strlen(s[1]);
        c[i].is=true,c[i].L=len[0];
        for(int j=0;j<len[0];j++){
            if(s[0][j]!=s[1][j]){
                c[i].is=false;
                break;
            }
        }
        for(int j=0;j<len[0];j++){
            if(s[0][j]==s[1][j]){
                c[i].a[0]=c[i].a[0]*base[1]%mod+(s[0][j]-'a')+1;
                if(c[i].a[0]>=mod)c[i].a[0]-=mod;
            }
            else {
                c[i].l=j;
                break;
            }
        }        
        for(int j=len[0]-1;j>=0;j--){
            if(s[0][j]!=s[1][j]){
                c[i].r=j;
                break;
            }
        }
        for(int j=c[i].r+1;j<len[0];j++){
            c[i].a[1]=c[i].a[1]*base[1]%mod+(s[0][j]-'a')+1;
            if(c[i].a[1]>=mod)c[i].a[1]-=mod;
        }
        for(int j=c[i].l;j<=c[i].r;j++){
            c[i].b[0]=c[i].b[0]*base[1]%mod+(s[0][j]-'a')+1;
            if(c[i].b[0]>=mod)c[i].b[0]-=mod;
            c[i].b[1]=c[i].b[1]*base[1]%mod+(s[1][j]-'a')+1;
            if(c[i].b[1]>=mod)c[i].b[1]-=mod;
        }
        mp[make_pair(c[i].b[0],c[i].b[1])].push_back(i);
    }
}
inline int get(int opt,int l,int r){
    int p=f[opt][r]-f[opt][l-1]*base[r-l+1]%mod+mod;
    if(p>=mod)p-=mod;
    return p;
}
inline void solve(){
    while(m--){
        scanf("%s%s",s[0],s[1]);
        len[0]=strlen(s[0]);
        len[1]=strlen(s[1]);
        int pl,pr;
        for(int j=0;j<len[0];j++){
            if(s[0][j]!=s[1][j]){
                pl=j;
                break;
            }
        }
        for(int j=len[0]-1;j>=0;j--){
            if(s[0][j]!=s[1][j]){
                pr=j;
                break;
            }
        }
        for(int j=0;j<len[0];j++){
            for(int k=0;k<=1;k++){
                f[k][j]=f[k][j-1]*base[1]%mod+(s[k][j]-'a')+1;
                if(f[k][j]>=mod)f[k][j]-=mod;
            }
        }
        int u=get(0,pl,pr),v=get(1,pl,pr);
        int ans=0;
        int Sbj=mp[make_pair(u,v)].size();
        for(int j=0;j<Sbj;j++){
            int i=mp[make_pair(u,v)][j];
            if(c[i].is)continue;
            if(c[i].r-c[i].l!=pr-pl)continue;
            if(pl<c[i].l||len[0]-pr<c[i].L-c[i].r)continue;
            if(get(0,pl,pr)==c[i].b[0]&&get(1,pl,pr)==c[i].b[1]&&get(0,pl-c[i].l,pl-1)==c[i].a[0]&&get(0,pr+1,pr+c[i].L-c[i].r-1)==c[i].a[1])++ans;
        }
        printf("%lld\n",ans);
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ipt();
    solve();
    return 0;
}