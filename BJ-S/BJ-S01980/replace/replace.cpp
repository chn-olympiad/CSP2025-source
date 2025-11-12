#include<bits/stdc++.h>
#define pir pair<int,int>
#define pbk push_back
using namespace std;
const int N=2e5+5,M=1e7+5,m=1e7,mod=998244353;
int n,q;
string s[2];
int lid,rid,mid;
struct trie{
    int son[26];
    int sz,dfn,L,R;
}t[M];
int dfncnt;
void dfs(int u){
    t[u].L=t[u].dfn=++dfncnt;
    t[u].sz=1;
    for(int i=0;i<26;i++){
        if(t[u].son[i]){
            dfs(t[u].son[i]);
            t[u].sz+=t[t[u].son[i]].sz;
        }
    }
    t[u].R=t[u].L+t[u].sz-1;
}
int cnt=1;
char a[M];
int acnt;
map<pir,int>id;
int idcnt;
int ans[N];
int insert(){
    int now=1;
    for(int i=1;i<=acnt;i++){
        if(t[now].son[a[i]-'a']==0)
            t[now].son[a[i]-'a']=++cnt;
        now=t[now].son[a[i]-'a'];
    }
    return now;
}
void solve(){
    int l=s[0].size(),r=-1;
    for(int i=0;i<s[0].size();i++){
        if(s[0][i]!=s[1][i])
            l=min(l,i),r=max(r,i);
    }
    //cout<<"!!"<<l<<" "<<r<<" ";
    if(r==-1){
        lid=-1,rid=-1;
        return;
    }
    //cout<<"!!"<<l<<" "<<r<<" "<<s[0].size()<<'\n';
    acnt=0;
    for(int i=l-1;i>=0;i--)a[++acnt]=s[0][i];
    lid=insert();
    acnt=0;
    for(int i=r+1;i<int(s[0].size());i++)a[++acnt]=s[0][i];
    rid=insert();
    int t1=0,t2=0;
    for(int i=l;i<=r;i++){
        t1=(1LL*t1*131+s[0][i])%mod;
        t2=(1LL*t2*131+s[1][i])%mod;
    }
    if(id[{t1,t2}]==0)id[{t1,t2}]=++idcnt;
    mid=id[{t1,t2}];
    //cout<<mid<<'\n';
    return;
}
struct node{
    int op,lid,rid;
};
vector<node>opt[2*N];
struct qry{
    int op,x,l,r,key;
    inline bool operator<(const qry &rhs)const{
        if(x!=rhs.x)return x<rhs.x;
        return op<rhs.op;
    }
}optt[3*N];
int optcnt;
struct binary_tree{
    int tree[M];
    inline int lowbit(int x){
        return x&(-x);
    }
    void add(int x,int key){
        if(x==0)x++;
        while(x<=m){
            tree[x]+=key;
            x+=lowbit(x);
        }
    }
    inline int qry(int x){
        int re=0;
        while(x){
            re+=tree[x];
            x-=lowbit(x);
        }
        return re;
    }
}bnt;
void solvee(int key){
    optcnt=0;
    for(node i:opt[key]){
        //cout<<"!!"<<key<<" "<<i.op<<" "<<i.lid<<" "<<i.rid<<'\n';
        if(i.op==0){
            optt[++optcnt]=qry{0,t[i.lid].L,t[i.rid].L,t[i.rid].R,1};
            optt[++optcnt]=qry{0,t[i.lid].R+1,t[i.rid].L,t[i.rid].R,-1};
        }
        else optt[++optcnt]=qry{1,t[i.lid].dfn,t[i.rid].dfn,0,i.op};
    }
    sort(optt+1,optt+optcnt+1);
    //cout<<"-----"<<'\n';
    for(int i=1;i<=optcnt;i++){
        //cout<<optt[i].x<<" "<<optt[i].op<<" "<<optt[i].l<<" "<<optt[i].r<<" "<<optt[i].key<<'\n';
        if(optt[i].op)
            ans[optt[i].key]=bnt.qry(optt[i].l);
        else{
            bnt.add(optt[i].l,optt[i].key);
            bnt.add(optt[i].r+1,optt[i].key*-1);
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[0]>>s[1];
        solve();
        if(lid==-1)
            continue;
        opt[mid].pbk(node{0,lid,rid});
    }
    for(int i=1;i<=q;i++){
        cin>>s[0]>>s[1];
        if(s[0].size()!=s[1].size())
            continue;
        solve();
        if(lid==-1)
            continue;
        opt[mid].pbk(node{i,lid,rid});
    }
    dfs(1);
    for(int i=1;i<=idcnt;i++){
        solvee(i);
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
    return 0;
}
