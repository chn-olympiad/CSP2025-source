#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define popcount __builtin_popcount
using namespace std;
int rd(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f*=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch-'0');
    return x*f;
}
const int N=2e5+5,M=5e6+5,INF=0x3f3f3f3f;
const ull p=13331;
ull pn[M+2];
int ans[N];
struct BIT{
    int c[M],lim;
    void Add(int x,int y){while(x<=lim) c[x]+=y,x+=lowbit(x);}
    void add(int l,int r,int op){Add(l,op),Add(r+1,op*-1);}
    int ask(int x){int res=0;while(x) res+=c[x],x-=lowbit(x);return res;}
}bit;

struct Trie{
    int tr[M][26],tot,L[M],R[M],cnt;
    vector<int> A[M];
    vector<pii> B[M];
    void init(){
        for(int i=0;i<=tot;i++){
            for(int j=0;j<26;j++) tr[i][j]=0;
            A[i].clear(),B[i].clear();
        }
        tot=cnt=0;
    }
    int ins(vector<char> &s){
        int len=s.size(),u=0,c;
        for(int i=0;i<len;i++){
            c=s[i]-'a';
            if(!tr[u][c]) tr[u][c]=++tot;
            u=tr[u][c];
        }return u;
    }
    int run(vector<char> &s){
        int len=s.size(),u=0,c;
        for(int i=0;i<len;i++){
            c=s[i]-'a';
            if(!tr[u][c]) return u;
            u=tr[u][c];
        }
        return u;
    }
    void dfs(int u){
        L[u]=++cnt;
        for(int c=0;c<26;c++) if(tr[u][c]) dfs(tr[u][c]);
        R[u]=++cnt;
    }
}tr[2];
void solve(int u){
    for(auto id : tr[0].A[u])bit.add(tr[1].L[id],tr[1].R[id],1);
    for(auto [p,id] : tr[0].B[u])ans[id]=bit.ask(p);
    for(int c=0;c<26;c++) if(tr[0].tr[u][c])solve(tr[0].tr[u][c]);
    for(auto id : tr[0].A[u])bit.add(tr[1].L[id],tr[1].R[id],-1);
}
int n,q,tot[2];
vector<char> A[2][N],B[2][N];
map<pair<ull,ull>,vector<int> > mp[2];
char S[M],T[M];
int a[N],b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=rd(),q=rd();
    pn[0]=1;for(int i=1;i<=M;i++) pn[i]=pn[i-1]*p;
    for(int i=1;i<=n;i++){
        scanf("%s%s",S+1,T+1);
        int len=strlen(S+1),j=0,k=len+1;
        while(j+1<=len&&S[j+1]==T[j+1]) j++;
        if(j==len) continue;
        while(k-1>=1&&S[k-1]==T[k-1]) k--;
        ull Ha1=0,Ha2=0;
        for(int x=j+1;x<k;x++) Ha1=Ha1*p+S[x],Ha2=Ha2*p+T[x];
        auto &vec=A[0][i];
        vec.resize(j);
        for(int x=1;x<=j;x++) vec[x-1]=S[x];
        reverse(vec.begin(),vec.end());
        auto &Vec=B[0][i];
        Vec.resize(len-k+1);
        for(int x=k,y=0;x<=len;x++,y++) Vec[y]=S[x];
        pair<ull,ull> tmp=m_p(Ha1,Ha2); 
        mp[0][tmp].p_b(i);
    }
    for(int i=1;i<=q;i++){
        scanf("%s%s",S+1,T+1);
        if(strlen(S+1)!=strlen(T+1)) continue;
        int len=strlen(S+1),j=0,k=len+1;
        while(j+1<=len&&S[j+1]==T[j+1]) j++;
        while(k-1>=1&&S[k-1]==T[k-1]) k--;
        ull Ha1=0,Ha2=0;
        for(int x=j+1;x<k;x++) Ha1=Ha1*p+S[x],Ha2=Ha2*p+T[x];
        auto &vec=A[1][i];
        vec.resize(j);
        for(int x=1;x<=j;x++) vec[x-1]=S[x];
        reverse(vec.begin(),vec.end());
        auto &Vec=B[1][i];
        Vec.resize(len-k+1);
        for(int x=k,y=0;x<=len;x++,y++) Vec[y]=S[x];
        pair<ull,ull> tmp=m_p(Ha1,Ha2); 
        mp[1][tmp].p_b(i);
    }
    for(auto [Ha,vec] : mp[1])if(mp[0].count(Ha)){
        auto &in=mp[0][Ha];
        tr[0].init(),tr[1].init();
        for(auto id : in){
            a[id]=tr[0].ins(A[0][id]),b[id]=tr[1].ins(B[0][id]);
            tr[0].A[a[id]].p_b(b[id]);
        }
        tr[1].dfs(0);bit.lim=tr[1].cnt;
        for(auto id : vec){
            int u=tr[0].run(A[1][id]),v=tr[1].run(B[1][id]);
            if(u==-1||v==-1) continue;
            tr[0].B[u].p_b(m_p(tr[1].L[v],id));
        }
        solve(0);
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
//g++ replace.cpp -o replace -std=c++14 -O2 -Wall -fsanitize=address,undefined