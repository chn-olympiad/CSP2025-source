#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define pii pair<int,int>
#define fir first
#define sec second
#define P(x,y) make_pair(x,y)
#define ll long long
using namespace std;
bool BG;

const int maxn=2e5+5;
const int maxc=5e6+5;
const int maxaz=27;

int n,q,endd[2][maxn],pre[maxn],suf[maxn];
string s[2][maxn],t[2][maxn];

int TOT,tot[2],ch[2][maxc][maxaz],fail[2][maxc];

inline void insert(int id,int id2){
    int p=0;
    for (int i=0;i<s[id][id2].size();i++){
        int chh=s[id][id2][i]-'a'+1;
        if (!ch[id][p][chh]) ch[id][p][chh]=++tot[id];
        p=ch[id][p][chh];
    }
    endd[id][id2]=p;
}

struct edge{
    int to,nxt;
}E[2][maxc];
int etot[2],hd[2][maxc];
inline void addE(int id,int x,int y){
    E[id][++etot[id]]=(edge){y,hd[id][x]};
    hd[id][x]=etot[id];
}

int head,tail;
int que[maxc];
inline void getfail(int id){
    head=0,tail=-1;
    for (int i=1;i<=26;i++) if (ch[id][0][i]) que[++tail]=ch[id][0][i],addE(id,0,ch[id][0][i]);
    while (head<=tail){
        int x=que[head++];
        for (int i=1;i<=26;i++){
            if (ch[id][x][i]){
                int up=ch[id][fail[id][x]][i];
                addE(id,up,ch[id][x][i]);
                fail[id][ch[id][x][i]]=up;
                que[++tail]=ch[id][x][i];
            }else{
                ch[id][x][i]=ch[id][fail[id][x]][i];
            }
        }
    }
}

int tim[2],dfn[2][maxc],siz[2][maxc];
inline void dfs(int id,int x){
    dfn[id][x]=++tim[id];
    siz[id][x]=1;
    for (int i=hd[id][x];i;i=E[id][i].nxt){
        int v=E[id][i].to;
        dfs(id,v);
        siz[id][x]+=siz[id][v];
    }
}

int p[2];

vector <pii> upd[maxc];
vector <pii> qry[maxc];
ll ans[maxn];

int c[maxc];
inline int lowbit(int x) {return x&-x; }
inline void add(int x,int k) {for (int i=x+1;i<=TOT;i+=lowbit(i)) c[i]+=k; }
inline int ask(int x){
    int res=0;
    for (int i=x+1;i;i-=lowbit(i)) res+=c[i];
    return res;
}

inline void write(ll x){
    if (x>9) write(x/10);
    putchar('0'+(x%10));
}

bool ED;
int main(){
    fin("replace.in");
    fout("replace.out");

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i];
    for (int i=1;i<=q;i++) cin>>t[0][i]>>t[1][i];

    for (int i=1;i<=n;i++) insert(0,i);
    for (int i=1;i<=n;i++) insert(1,i);

    getfail(0);
    getfail(1);

    dfs(0,0);
    dfs(1,0);

    TOT=max(tot[0],tot[1]);

    for (int i=1;i<=n;i++){
        int u=endd[0][i],v=endd[1][i];
        upd[dfn[0][u]].push_back(P(dfn[1][v],dfn[1][v]+siz[1][v]-1));
        upd[dfn[0][u]+siz[0][u]].push_back(P(-dfn[1][v],-(dfn[1][v]+siz[1][v]-1)));
    }

    int rem_qry=0;
    for (int i=1;i<=q;i++){
        for (int j=0;j<t[0][i].size();j++){
            if (t[0][i][j]!=t[1][i][j]){
                pre[i]=j;
                break;
            }
        }
        for (int j=(int)t[0][i].size()-1;~j;j--){
            if (t[0][i][j]!=t[1][i][j]){
                suf[i]=j;
                break;
            }
        }
        p[0]=0,p[1]=0;
        for (int j=0;j<t[0][i].size();j++){
            p[0]=ch[0][p[0]][t[0][i][j]-'a'+1];
            p[1]=ch[1][p[1]][t[1][i][j]-'a'+1];
            if (j<suf[i]) continue;
            qry[dfn[0][p[0]]].push_back(P(dfn[1][p[1]],i));
            rem_qry++;
        }
        p[0]=0,p[1]=0;
        for (int j=pre[i]+1;j<t[0][i].size();j++){
            p[0]=ch[0][p[0]][t[0][i][j]-'a'+1];
            p[1]=ch[1][p[1]][t[1][i][j]-'a'+1];
            if (j<suf[i]) continue;
            qry[dfn[0][p[0]]].push_back(P(-dfn[1][p[1]],-i));
            rem_qry++;
        }
    }
    for (int i=0;i<=TOT && rem_qry;i++){
        for (int j=0;j<upd[i].size();j++){
            int L=upd[i][j].fir,R=upd[i][j].sec;
            if (L<0 && R<0){
                L=-L,R=-R;
                add(L,-1),add(R+1,1);
            }else{
                add(L,1),add(R+1,-1);
            }
        }
        for (int j=0;j<qry[i].size();j++){
            rem_qry--;
            if (qry[i][j].sec>0) ans[qry[i][j].sec]+=ask(qry[i][j].fir);
            else ans[-qry[i][j].sec]-=ask(-qry[i][j].fir);
        }
    }

    for (int i=1;i<=q;i++) write(ans[i]),putchar('\n');

    cerr<<"Memory : "<<1.0*(&ED-&BG)/1048576<<"Mb\n";
    return 0;
}
