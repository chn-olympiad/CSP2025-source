#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define fi first
#define se second
#define pb push_back

struct node {
    int son[27];
    int fail,cnt,len;
} tr[2500005];
const int tt=26;

unordered_map<ull,int> Id; int nc=0;
int rot[2500005];
const ull Md=499999999999993ull,base=10007;

int n,q;
char s[2500005],t[2500005],str[2500005];
int tot=0;

int op(int x) {return (s[x]-'a')*26+t[x]-'a';}

void ins(int now) {
    for(int i=1;str[i];++i) {
        int nxt=str[i]-'a',&u=tr[now].son[nxt];
        if(!u) u=++tot,tr[u].len=tr[now].len+1; now=u;
    }
    ++tr[now].cnt;
}

queue<int> qq;
vector<int> o;

int g[2500005],fa[2500005];

vector<int> v[2500005];

void build(int now) { 
    for(int i=0;i<=tt;++i) {
        if(tr[now].son[i]) qq.push(tr[now].son[i]),tr[tr[now].son[i]].fail=now;
        else tr[now].son[i]=now;
    } o.clear();
    for(int tp;!qq.empty();qq.pop()) {
        tp=qq.front(); o.pb(tp);
        for(int i=0;i<=tt;++i) {
            if(tr[tp].son[i]) {
                tr[tr[tp].son[i]].fail=tr[tr[tp].fail].son[i];
                qq.push(tr[tp].son[i]);
            }
            else tr[tp].son[i]=tr[tr[tp].fail].son[i];
        }
    }
    for(auto i:o) fa[i]=tr[i].fail,v[fa[i]].pb(i); 
    for(auto u:o) g[u]=g[fa[u]]+tr[u].cnt;
}

ll qry(int now) {
    ll res=0;
    for(int i=1;str[i];++i) {
        int nxt=str[i]-'a',&u=tr[now].son[nxt]; now=u;
        res=res+g[now];
    }
    return res;
}

void wk() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i) {
        scanf("%s%s",s+1,t+1);
        int fi=-1,se=-1;
        for(int j=1;s[j];++j) {
            if(s[j]==t[j]) continue;
            if(fi==-1) fi=j; se=j;
        }
        if(fi==-1) {
            int le=strlen(s+1);
            for(int j=1;j<=le;++j) str[j]=s[j]; str[le+1]=0;
            ins(0);
        }
        else {
            ull hsh=0;
            for(int j=fi;j<=se;++j) hsh=hsh*base+op(j)+1;
            if(!Id[hsh]) Id[hsh]=++nc,rot[nc]=++tot;
            int le=0;
            for(int j=1;j<fi;++j) str[++le]=s[j];
            str[++le]='z'+1; for(int j=se+1;s[j];++j) str[++le]=s[j]; str[++le]=0;
            ins(rot[Id[hsh]]);
        }
    }
    for(int i=0;i<=nc;++i) build(rot[i]);
    for(int i=1;i<=q;++i) {    
        scanf("%s%s",s+1,t+1);
        if(strlen(s+1)!=strlen(t+1)) {printf("0\n");continue ;}
        int fi=-1,se=-1; 
        for(int j=1;s[j];++j) {
            if(s[j]==t[j]) continue;
            if(fi==-1) fi=j; se=j;
        }
        if(fi==-1) {
            int le=strlen(s+1);
            for(int j=1;j<=le;++j) str[j]=s[j]; str[le+1]=0;
            printf("%lld\n",qry(0));
        }
        else {
            ull hsh=0;
            for(int j=fi;j<=se;++j) hsh=hsh*base+op(j)+1;
            int le=0; //assert(rot[Id[hsh]]);
            if(!rot[Id[hsh]]) {printf("0\n");continue ;}
            for(int j=1;j<fi;++j) str[++le]=s[j];
            str[++le]='z'+1; for(int j=se+1;s[j];++j) str[++le]=s[j]; str[++le]=0;
            printf("%lld\n",qry(rot[Id[hsh]]));
        }
    }
}

signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    wk();

    return 0;
}

// Make asdfz great again!
/*
password:
Ren5Jie4Di4Ling5%
*/