#include<bits/stdc++.h>
using namespace std;
constexpr long long p1=233,mod1=1e9+7,p2=197,mod2=998244353;
struct node{
    int x,y,idx;
}d[200005];
struct query{
    int x,l,r,t;
}e[400005];
int n,q,cnt,ans[200005],sl[200005],sr[200005],tl[200005],tr[200005],cnt1,cnt2;
string s1[200005],s2[200005],t1[200005],t2[200005];
pair<int,int> pos[200005];
map<long long,int> Map;
vector<int> s[200005],t[200005];
namespace binary{
    int c[2500005],tot;
#define lowbit(v) v&-v
    inline void init(int t){
        tot=t;
    }
    inline void modify(int v,int t){
        for(;v<=tot;v+=lowbit(v)) c[v]+=t;
    }
    inline int getsum(int v){
        int res=0;
        for(;v;v^=lowbit(v)) res+=c[v];
        return res;
    }
#undef lowbit
}
namespace trie{
    int go[2500005][26],st[2500005][26],top[2500005],cnt,in[2500005],out[2500005],num;
    inline void init(){
        for(int i=0;i<=cnt;i++){
            for(int j=0;j<top[i];j++) go[i][st[i][j]]=0;
            top[i]=0;
        }
        cnt=1;
    }
    inline pair<int,int> add(string&s,int l,int r){
        int v1=0,v2=1,len=s.size();
        for(int i=l;i>=0;i--){
            int c=s[i]-'a';
            if(go[v1][c]) v1=go[v1][c];
            else st[v1][top[v1]++]=c,v1=go[v1][c]=++cnt;
        }
        for(int i=r;i<len;i++){
            int c=s[i]-'a';
            if(go[v2][c]) v2=go[v2][c];
            else st[v2][top[v2]++]=c,v2=go[v2][c]=++cnt;
        }
        return make_pair(v1,v2);
    }
    void dfs(int v){
        in[v]=++num;
        for(int i=0;i<top[v];i++) assert(go[v][st[v][i]]),dfs(go[v][st[v][i]]);
        out[v]=num;
    }
    inline void build(){
        num=0,dfs(0),num=0,dfs(1),binary::init(num);
    }
    inline pair<int,int> query(string &s,int l,int r){
        int v1=0,v2=1,len=s.size();
        for(int i=l;i>=0;i--){
            int c=s[i]-'a';
            if(go[v1][c]) v1=go[v1][c];
            else break;
        }
        for(int i=r;i<len;i++){
            int c=s[i]-'a';
            if(go[v2][c]) v2=go[v2][c];
            else break;
        }
        return make_pair(v1,v2);
    }
}
inline long long getha(string&a,string&b,int&l,int&r){
    int len=a.size();
    l=0,r=len-1;
    while(a[l]==b[l]) l++;
    while(a[r]==b[r]) r--;
    long long ha1=0,ha2=0;
    for(int i=l;i<=r;i++) ha1=(ha1*p1+a[i])%mod1,ha2=(ha2*p2+a[i])%mod2;
    for(int i=l;i<=r;i++) ha1=(ha1*p1+b[i])%mod1,ha2=(ha2*p2+b[i])%mod2;
    return ha1*mod2+ha2;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        if(s1[i]==s2[i]) continue;
        long long tmp=getha(s1[i],s2[i],sl[i],sr[i]);
        if(Map.count(tmp)) s[Map[tmp]].emplace_back(i);
        else Map[tmp]=++cnt,s[cnt].emplace_back(i);
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        if(t1[i].size()!=t2[i].size()) continue;
        long long tmp=getha(t1[i],t2[i],tl[i],tr[i]);
        if(Map.count(tmp)) t[Map[tmp]].emplace_back(i);
    }
    for(int i=1;i<=cnt;i++){
        if(t[i].empty()) continue;
        trie::init(),cnt1=cnt2=0;
        for(int j:s[i]) pos[j]=trie::add(s1[j],sl[j]-1,sr[j]+1);
        trie::build();
        for(int j:s[i]){
            e[++cnt1]=query{trie::in[pos[j].first],trie::in[pos[j].second],trie::out[pos[j].second],1};
            e[++cnt1]=query{trie::out[pos[j].first]+1,trie::in[pos[j].second],trie::out[pos[j].second],-1};
        }
        for(int j:t[i]){
            pair<int,int> tmp=trie::query(t1[j],tl[j]-1,tr[j]+1);
            d[++cnt2]=node{trie::in[tmp.first],trie::in[tmp.second],j};
        }
        sort(e+1,e+1+cnt1,[](query&x,query&y)->bool{return x.x<y.x;});
        sort(d+1,d+1+cnt2,[](node&x,node&y)->bool{return x.x<y.x;});
        int j=1;
        for(int i=1;i<=cnt2;i++){
            while(j<=cnt1&&e[j].x<=d[i].x) binary::modify(e[j].l,e[j].t),binary::modify(e[j].r+1,-e[j].t),j++;
            ans[d[i].idx]=binary::getsum(d[i].y);
        }
        while(j<=cnt1) binary::modify(e[j].l,e[j].t),binary::modify(e[j].r+1,-e[j].t),j++;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
    return 0;
}