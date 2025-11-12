#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const ull bas=131;

const int N=2e5+5;
int n,m;
const int M=5e6+5;

queue<int>q;
struct AC {
    int tot;
    vector<int> ch[27],fl,vs,cnt;
    inline void init (int L) {
        vs.resize(L+3),fl.resize(L+3),cnt.resize(L+3);
        for (int j=0;j<=26;++j) ch[j].resize(L+3);
    }
    inline int newnode() {
        ++tot; 
        return tot;
    }
    inline void ins (string s) {
        int p=0;
        for (int i=0,j;i<s.size();++i) {
            j=s[i]-'a';
            if (!ch[j][p]) ch[j][p]=newnode();
            p=ch[j][p];
        }
        ++cnt[p];
    }
    inline void ac(){
        for (int i=0;i<=26;++i) if (ch[i][0]) q.push(ch[i][0]);
        for (int u;!q.empty();) {
            u=q.front(); q.pop();
            for (int i=0;i<=26;++i) {
                if (ch[i][u]) {fl[ch[i][u]]=ch[i][fl[u]]; q.push(ch[i][u]);}
                else ch[i][u]=ch[i][fl[u]];
            }
        }
    }
    inline int ask (string s,int id) {
        int p=0,res=cnt[0];
        for (int i=0,j;i<s.size();++i) {
            j=s[i]-'a';
            p=ch[j][p];
            for (int v=p;v && vs[v]!=id;v=fl[v]) {
                res+=cnt[v]; vs[v]=id;
            }
        }
        return res;
    }
} T[N];

char s[2][M];

map<pair<ull,ull>,int>id; int idx;
int bl[N],sz[N];
string ss[N];
char t0[M],t1[M];

int main () {
    freopen ("replace.in","r",stdin);
    freopen ("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1,lp,rp,x,len;i<=n;++i) {
        scanf("%s%s",s[0],s[1]); len=strlen(s[0]);
        for(lp=0;lp<len && s[0][lp]==s[1][lp];++lp);
        if (lp>=len) continue;
        for(rp=len-1;rp>=0 && s[0][rp]==s[1][rp];--rp);
        ull h1=0,h2=0;
        for (int j=lp;j<=rp;++j) h1=h1*bas+s[0][j],h2=h2*bas+s[1][j];
        if (id[{h1,h2}]) x=id[{h1,h2}];
        else x=id[{h1,h2}]=++idx;
        sz[x]+=len; bl[i]=x;
        ss[i]="";
        for (int j=0;j<lp;++j) ss[i].push_back(s[0][j]);
        ss[i].push_back('a'+26);
        for (int j=rp+1;j<len;++j) ss[i].push_back(s[0][j]);
    }
    for (int i=1;i<=idx;++i) T[i].init(sz[i]);
    for (int i=1,lp,rp,x;i<=n;++i) {
        x=bl[i];
        if (!x) continue;        
        T[x].ins(ss[i]);
        // cout<<x<<" "<<ss<<"\n";
    }
    for (int i=1;i<=idx;++i) T[i].ac();
    int qc=1;
    for (;m--;++qc) {
        scanf("%s%s",t0,t1); 
        if (strlen(t0)!=strlen(t1)) {puts("0"); continue;}
        int lp,rp,x,len=strlen(t0);
        for(lp=0;lp<len && t0[lp]==t1[lp];++lp);
        for(rp=len-1;rp>=0 && t0[rp]==t1[rp];--rp);
        ull h1=0,h2=0;
        for (int j=lp;j<=rp;++j) h1=h1*bas+t0[j],h2=h2*bas+t1[j];
        if (!id[{h1,h2}]) {puts("0"); continue;}
        x=id[{h1,h2}];
        // cout<<x<<"@@@@\n";
        string ss="";
        for (int j=0;j<lp;++j) ss.push_back(t0[j]);
        ss.push_back('a'+26);
        for (int j=rp+1;j<len;++j) ss.push_back(t0[j]);
        // cout<<ss<<"\n";
        printf ("%d\n",T[x].ask(ss,qc));
    }
    return 0;
}