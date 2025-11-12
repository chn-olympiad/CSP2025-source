#include<bits/stdc++.h>
#include<bits/extc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int maxn=2e5+10;
const int B1=67,M1=998244353;
const int B2=71,M2=1e9+7;
const int B3=233,M3=1011451423;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int n,q;
string s1[maxn],s2[maxn],t1[maxn],t2[maxn];
int L[maxn],R[maxn],L2[maxn],R2[maxn];
struct H{
    size_t operator()(pair<tuple<int,int,int>,tuple<int,int,int> >a)const{
        return (get<0>(a.p1))^(get<1>(a.p2));
    }
};
gp_hash_table<pair<tuple<int,int,int>,tuple<int,int,int> >,vector<int>,H>mp,mp2;
#define N 5000005
vector<pi>G[N+5];
struct trie{
    int son[N+5][26],dfn[N+5],siz[N+5],tot,cnt;
    void clear(){up(i,0,tot)memset(son[i],0,sizeof(son[i])),dfn[i]=siz[i]=0;tot=cnt=0;}
    int add(string s){
        int u=0;
        for(char ch:s){
            if(!son[u][ch-'a'])son[u][ch-'a']=++tot;
            u=son[u][ch-'a'];
        }
        return u;
    }
    void dfs(int u){
        dfn[u]=++cnt;siz[u]=1;
        up(i,0,25)if(son[u][i])dfs(son[u][i]),siz[u]+=siz[son[u][i]];
    }
}A,B;
int id1[maxn],id2[maxn];
struct BIT {
    int t[N+5];
    int lb(int x){return x&(-x);}
    void upd(int x,int v){for(;x<=N;x+=lb(x))t[x]+=v;}
    int qr(int x){int res=0;for(;x;x-=lb(x))res+=t[x];return res;}
}T;
int res[maxn];
void dfs(int u){
    for(auto it:G[u])if(it.p2==1)T.upd(B.dfn[it.p1],1),T.upd(B.dfn[it.p1]+B.siz[it.p1],-1);
    for(auto it:G[u])if(it.p2<0)res[-it.p2]=T.qr(B.dfn[it.p1]);
    up(i,0,25)if(A.son[u][i])dfs(A.son[u][i]);
    for(auto it:G[u])if(it.p2==1)T.upd(B.dfn[it.p1],-1),T.upd(B.dfn[it.p1]+B.siz[it.p1],1);
}
string rd(){
    char ch=getchar();string a;
    while(ch<'a'||ch>'z')ch=getchar();
    while(ch>='a'&&ch<='z')a.p_b(ch),ch=getchar();
    return a;
}
void slv(){
    n=read(),q=read();
    up(i,1,n)s1[i]=rd(),s2[i]=rd();
    up(i,1,q)t1[i]=rd(),t2[i]=rd();
    auto sol=[&](string s1,string s2,int &p,int &q){
        p=0,q=s1.size()-1;
        while(s1[p]==s2[p])p++;
        while(s1[q]==s2[q])q--;
        auto qr=[&](int l,int r,string s){
            int A=0,B=0,C=0;
            up(i,l,r){
                char ch=s[i];
                A=(A*1llu*B1+ch-'a'+1)%M1,B=(B*1llu*B2+ch-'a'+1)%M2,C=(C*1llu*B3+ch-'a'+1)%M3;
            }return make_tuple(A,B,C);
        };
        auto x=qr(p,q,s1),y=qr(p,q,s2);
        return m_p(x,y);
    };
    up(i,1,n){
        if(s1[i]==s2[i])continue;
        mp[sol(s1[i],s2[i],L[i],R[i])].p_b(i);
    }
    up(i,1,q)if(t1[i].size()==t2[i].size())mp2[sol(t1[i],t2[i],L2[i],R2[i])].p_b(i);
    for(auto it:mp)if(mp2.find(it.p1)!=mp2.end()){
        up(i,0,A.tot)G[i].clear();
        A.clear(),B.clear();
        for(int x:it.p2){
            string a,b;
            down(j,L[x]-1,0)a.p_b(s1[x][j]);
            up(j,R[x]+1,(int)s1[x].size()-1)b.p_b(s1[x][j]);
            id1[x]=A.add(a),id2[x]=B.add(b);
            G[id1[x]].p_b({id2[x],1});
        }
        for(int x:mp2[it.p1]){
            string a,b;
            down(j,L2[x]-1,0)a.p_b(t1[x][j]);
            up(j,R2[x]+1,(int)t1[x].size()-1)b.p_b(t1[x][j]);
            id1[x]=A.add(a),id2[x]=B.add(b);
            G[id1[x]].p_b({id2[x],-x});
        }
        A.dfs(0),B.dfs(0);dfs(0);
    }
    up(i,1,q)printf("%d\n",res[i]);
}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    slv();
    return 0;
}