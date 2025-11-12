#include<bits/stdc++.h>
namespace xcy{
typedef int ll;
typedef std::pair<ll,ll> sp;
const int MAXN=200005;
const int MAXV=5000005;
const int MX=5000001;
#define fi first
#define se second
#define emb emplace_back
ll ch[MAXV<<1][26],ans[MAXN],fail[MAXV],res[MAXV],q[MAXV],h,t,cnt=2,num,n,m,p,i,j,k,x,y,l,r;
std::vector<ll>s1,s2,a1[MAXN],a2[MAXN],t1[MAXN],t2[MAXN];
struct Nd{ll id,op,x,y,l,r;Nd(ll I=0,ll O=0,ll X=0,ll Y=0,ll L=0,ll R=0){id=I,op=O,x=X,y=Y,l=L,r=R;}}nd[MAXN<<1];

inline void fr(ll &X){ll A=1;X=0;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();
    if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void out(const ll X){if(!X)return;out(X/10);putchar(X%10+'0');}
inline void fo(ll X,const char C=' '){if(X<0)putchar('-'),X=-X;if(!X)putchar('0');out(X);putchar(C);}
inline void get(std::vector<ll> &V){ll C=getchar();V.clear();
    while(!isalpha(C))C=getchar();while(isalpha(C))V.emb(C-'a'),C=getchar();}
inline ll getson(const ll &X,const ll &C){return ch[X][C]?ch[X][C]:(ch[X][C]=++cnt);}
inline void reset(){memset(fail,0,(cnt+2)*4);memset(res,0,(cnt+2)*4);
    memset(ch,0,(cnt+2)*4*26);cnt=1;for(ll I=0;I<26;++I)ch[0][I]=1;}
inline void insert(std::vector<ll>&V){ll I=1;for(auto C:V)I=getson(I,C);++res[I];}
inline void build()
{
    q[h=t=1]=1;ll N,I,J;while(h<=t)
        {N=q[h++];for(I=0;I<26;++I)if(!(J=ch[N][I]))ch[N][I]=ch[fail[N]][I];
            else res[J]+=res[fail[J]=ch[fail[N]][I]],q[++t]=J;}
}
inline ll qry(std::vector<ll>&V){ll I=1,Res=0;for(auto C:V)I=ch[I][C],Res+=res[I];return Res;}
inline void solve(ll L,ll R)
{
    reset();for(ll I=L;I<=R;++I)if(!nd[I].op)insert(a1[nd[I].id]);build();
    for(ll I=L;I<=R;++I)if(nd[I].op)ans[nd[I].id]=qry(t1[nd[I].id]);
}

int mian()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    fr(n);fr(m);for(i=1;i<=n;++i)
    {
        get(s1),get(s2);a1[i]=s1,a2[i]=s2;
        for(l=0;l<s1.size()&&s1[l]==s2[l];++l);if(l==s1.size())continue;
        for(r=s1.size()-1;(~r)&&s1[r]==s2[r];--r);
        for(x=1,k=l;k<=r;x=getson(x,s1[k]),++k);
        for(y=2,k=l;k<=r;y=getson(y,s2[k]),++k);
        nd[++num]=Nd(i,0,x,y,l,s1.size()-1-r);
    }
    for(i=1;i<=m;++i)
    {
        get(s1),get(s2);if(s1.size()!=s2.size())continue;t1[i]=s1,t2[i]=s2;
        for(l=0;l<s1.size()&&s1[l]==s2[l];++l);
        for(r=s1.size()-1;(~r)&&s1[r]==s2[r];--r);
        for(x=1,k=l;k<=r;x=ch[x][s1[k]],++k);
        for(y=2,k=l;k<=r;y=ch[y][s2[k]],++k);
        nd[++num]=Nd(i,1,x,y,l,s1.size()-1-r);
    }
    std::sort(nd+1,nd+num+1,[&](Nd A,Nd B){
        if(A.x!=B.x)return A.x<B.x;if(A.y!=B.y)return A.y<B.y;
        if(A.l!=B.l)return A.l<B.l;return A.op<B.op;});
    for(l=1;l<=num;l=r+1)
        {for(r=l+1;nd[r].x==nd[l].x&&nd[r].y==nd[l].y;++r);--r;solve(l,r);}
    for(i=1;i<=m;++i)fo(ans[i],'\n');
    return 0;
}}
int main(){return xcy::mian();}