#include<bits/stdc++.h>
#define ull unsigned long long
#define mk make_pair
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return b<a?a:b;}
const int N=2e5+5,S=5e6+N+5,B=43;
int n,q;
int an[N];
char s1[S],s2[S],tmp[S];
map<pair<ull,ull>,int> mp;int fir[N],nn;
int tr[S][27],cnt,s[S],fail[S];
int anc[S][23],lg[S],dep[S];
void ins(int p,int len){
    for(int j=0;j<len;++j){
        int &to=tr[p][tmp[j]-'a'];
        if(!to) to=++cnt;
        p=to;
    }
    s[p]++;
}
void build(int p){
    queue<int> q;
    fail[p]=p;
    for(int i=0;i<27;++i){
        if(tr[p][i]) q.push(tr[p][i]);
        else tr[p][i]=p;
        fail[tr[p][i]]=p;
    }
    for(int i=0;i<23;++i) anc[p][i]=p;
    dep[p]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<27;++i){
            if(!tr[u][i]) tr[u][i]=tr[fail[u]][i];
            else{
                fail[tr[u][i]]=tr[fail[u]][i];
                q.push(tr[u][i]);
            }
        }
        s[u]+=s[fail[u]];dep[u]=dep[fail[u]]+1;
        anc[u][0]=fail[u];
        for(int i=1;i<23;++i) anc[u][i]=anc[anc[u][i-1]][i-1];
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int j=mn(22,lg[dep[x]]+1);j>=0&&dep[x]^dep[y];--j) if(dep[anc[x][j]]>=dep[y]) x=anc[x][j];
    if(x==y) return x;
    for(int j=mn(22,lg[dep[x]]+1);j>=0;j--) if(anc[x][j]^anc[y][j]) x=anc[x][j],y=anc[y][j];
    return anc[x][0];
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    for(int i=2;i<S;++i) lg[i]=lg[i/2]+1;
    in(n),in(q);
    for(int i=1;i<=n;++i){
        scanf("%s%s",s1,s2);
        int l=strlen(s1),j=0,k=l-1;
        while(j<l&&s1[j]==s2[j]) j++;
        while(k>=0&&s1[k]==s2[k]) k--;
        if(j==l) continue;
        ull h=0,h2=0;
        for(int z=j;z<=k;++z) h=h*B+s1[z]-'a'+1,h2=h2*B+s2[z]-'a'+1;
        if(!mp.count(mk(h,h2))) mp[mk(h,h2)]=++nn,fir[nn]=++cnt;
        int tp=0;
        for(int p=0;p<j;++p) tmp[tp++]=s1[p];
        tmp[tp++]='z'+1;
        for(int p=k+1;p<l;++p) tmp[tp++]=s1[p];
        ins(fir[mp[mk(h,h2)]],tp);
    }
    for(int i=1;i<=nn;++i) build(fir[i]);
    for(int i=1;i<=q;++i){
        scanf("%s%s",s1,s2);
        int l=strlen(s1),l2=strlen(s2),j=0,k=l-1;
        if(l^l2) continue;
        while(j<l&&s1[j]==s2[j]) j++;
        while(k>=0&&s1[k]==s2[k]) k--;
        ull h=0,h2=0;
        for(int z=j;z<=k;++z) h=h*B+s1[z]-'a'+1,h2=h2*B+s2[z]-'a'+1;
        if(!mp.count(mk(h,h2))){an[i]=0;continue;}
        int tp=0;
        for(int p=0;p<j;++p) tmp[tp++]=s1[p];
        tmp[tp++]='z'+1;
        for(int p=k+1;p<l;++p) tmp[tp++]=s1[p];
        for(int u=fir[mp[mk(h,h2)]],j=0,lst=u;j<tp;++j,lst=u){
            u=tr[u][tmp[j]-'a'];
            an[i]+=s[u]-s[lca(u,lst)];
        }
    }
    for(int i=1;i<=q;++i) printf("%d\n",an[i]);
    return 0;
}
