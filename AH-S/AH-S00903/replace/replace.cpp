#include <bits/stdc++.h>
using namespace std;
const int N=2e5,L=2e6; //
int n,q,glg[L+5];
struct ACAM{
    int ch[L+5][26],fail[L+5],cnt=0,p[N+5],dfn[L+5],sz[L+5],ttt=0,dep[L+5],fa[25][L+5],md=0,df[L+5];
    vector<vector<int> > G;
    ACAM(){G.resize(L+5);}
    void ins(const string &s,int id){
        int now=0,len=s.size();
        for(int i=0;i<len;++i){
            int w=s[i]-'a';
            if(!ch[now][w]){
                ch[now][w]=++cnt;
                dep[cnt]=i+1;
            }
            now=ch[now][w];
        }
        p[id]=now;
    }
    void build(){
        queue<int> q;
        for(int i=0;i<=25;++i){
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            G[fail[x]].push_back(x);
            for(int i=0;i<=25;++i){
                if(ch[x][i]){
                    fail[ch[x][i]]=ch[fail[x]][i];
                    q.push(ch[x][i]);
                }
                else ch[x][i]=ch[fail[x]][i];
            }
        }
    }
    void dfs(int x){
        dfn[x]=++ttt; sz[x]=1;
        md=max(md,df[x]+2);
        for(auto y:G[x]){
            fa[0][y]=x; df[y]=df[x]+1;
            dfs(y);
            sz[x]+=sz[y];
        }
    }
    void init(){
        build();
        dfs(0);
        for(int i=1;i<=glg[md];++i){
            for(int j=1;j<=cnt;++j) fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
    int jmp(int x,int k){ // the fist whose depth < k
        if(dep[x]<k) return x;
        for(int i=glg[df[x]+1];i>=0;--i){
            int y=fa[i][x];
            if(dep[y]>=k) x=y;
        }
        assert(dep[x]>=k);
        assert(dep[fa[0][x]]<k);
        return fa[0][x];
    }
}T1,T2;
struct www{
    int x,y,v,fl;
    // fl=0 -> upd;
    // fl=1/2 -> que. (+/-)
}k[4*L+4*N+5];
int kt=0,un;
long long ans[N+5];
bool cmp(www A,www B){
    if(A.y==B.y) return A.fl<B.fl;
    else return A.y<B.y;
}
int t[L+5];
void add(int x,int v){
    while(x<=un){
        t[x]+=v;
        x+=(x & -x);
    }
}
int sum(int x){
    int res=0;
    while(x>0){
        res+=t[x];
        x-=(x & -x);
    }
    return res;
}
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i<=L+3;++i) glg[i]=glg[i>>1]+1;
    cin >> n >> q;
    for(int i=1;i<=n;++i){
        string s1,s2; cin >> s1 >> s2;
        T1.ins(s1,i);
        T2.ins(s2,i);
    }
    T1.init();
    T2.init();
    un=max(T1.cnt,T2.cnt)+2;
    for(int i=1;i<=n;++i){
        int a=T1.dfn[T1.p[i]]; int c=a+T1.sz[T1.p[i]]-1;
        int b=T2.dfn[T2.p[i]]; int d=b+T2.sz[T2.p[i]]-1;
        k[++kt]=(www){a,b,1,0};
        k[++kt]=(www){a,d+1,-1,0};
        k[++kt]=(www){c+1,b,-1,0};
        k[++kt]=(www){c+1,d+1,1,0};
    }
    for(int o=1;o<=q;++o){
        string t1,t2;
        cin >> t1 >> t2;
        if(t1.size()!=t2.size()) continue;
        int len=t1.size(); int l=0,r=len-1,x=0,y=0;
        for(int i=0;i<len;++i){
            if(t1[i]!=t2[i]){
                l=i;
                break;
            }
        }
        for(int i=len-1;i>=0;--i){
            if(t1[i]!=t2[i]){
                r=i;
                break;
            }
        }
        for(int i=0;i<len;++i){
            x=T1.ch[x][t1[i]-'a'];
            y=T2.ch[y][t2[i]-'a'];
            if(i<r) continue;
            int lim=i-l+1;
            if(T1.dep[x]<lim || T2.dep[y]<lim) continue;
            int ux=T1.jmp(x,lim),uy=T2.jmp(y,lim);
            k[++kt]=(www){T1.dfn[x],T2.dfn[y],o,1};
            if(uy) k[++kt]=(www){T1.dfn[x],T2.dfn[uy],o,2};
            if(ux) k[++kt]=(www){T1.dfn[ux],T2.dfn[y],o,2};
            if(ux && uy) k[++kt]=(www){T1.dfn[ux],T2.dfn[uy],o,1};
        }
    }
    sort(k+1,k+kt+1,cmp);
    for(int i=1;i<=kt;++i){
        if(!k[i].fl) add(k[i].x,k[i].v);
        else ans[k[i].v]+=(k[i].fl==1?1:-1)*sum(k[i].x);
    }
    for(int i=1;i<=q;++i) cout << ans[i] << '\n';
    return 0;
}