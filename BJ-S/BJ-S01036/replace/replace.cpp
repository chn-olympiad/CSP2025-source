#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<random>
using namespace std;
const int maxn=200005;
const int maxm=5000005;
typedef long long ll;
const ll mod=1926081719260817011;
ll bas;
mt19937_64 rng(0x0d000721);
int n,m,ans[maxn],cnt,root1,root2,ct,idx[maxm],siz[maxm];
char s1[maxm],s2[maxm];
string str1[maxn*2],str2[maxn*2];
pair<ll,int> que[maxn*2];
vector<pair<int,int>> vc[maxm];
struct node{
    int son[26];
}pool[maxm];
int newNode(){
    ++cnt;
    for(int i=0;i<26;++i)pool[cnt].son[i]=0;
    vc[cnt].clear();
    return cnt;
}
int insert(int x,int y,string& str){
    if(y==str.size())return x;
    int g=(str[y])-'a';
    if(!pool[x].son[g])pool[x].son[g]=newNode();
    return insert(pool[x].son[g],y+1,str);
}
int fd(int x,int y,string& str){
    if(y==str.size())return x;
    int g=(str[y])-'a';
    if(!pool[x].son[g])return x;
    return fd(pool[x].son[g],y+1,str);
}
void dfs(int s){
    idx[s]=++ct;siz[s]=1;
    for(int j=0;j<26;++j)if(pool[s].son[j]){
        dfs(pool[s].son[j]);
        siz[s]+=siz[pool[s].son[j]];
    }
}
int lowbit(int x){return x&-x;}
struct BIT{
    int dat[maxm];
    void add(int x,int y){
        for(;x<=cnt;x+=lowbit(x))dat[x]+=y;
    }
    void add(int l,int r,int x){
        add(l,x);
        add(r+1,-x);
    }
    int query(int x){
        int res=0;
        for(;x;x-=lowbit(x))res+=dat[x];
        return res;
    }
}bit;
void dfs_(int s){
    for(int i=0;i<vc[s].size();++i)if(vc[s][i].first==0){
        int x=vc[s][i].second;
        bit.add(idx[x],idx[x]+siz[x]-1,1);
    }
    for(int i=0;i<vc[s].size();++i)if(vc[s][i].first){
        int x=vc[s][i].second;
        ans[vc[s][i].first]=bit.query(idx[x]);
    }
    for(int j=0;j<26;++j)if(pool[s].son[j]){
        dfs_(pool[s].son[j]);
    }
    for(int i=0;i<vc[s].size();++i)if(vc[s][i].first==0){
        int x=vc[s][i].second;
        bit.add(idx[x],idx[x]+siz[x]-1,-1);
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    bas=rng()%mod;
    cin>>n>>m;
    for(int i=1;i<=n+m;++i){
        cin>>s1+1>>s2+1;
        int len=strlen(s1+1);
        if(len!=strlen(s2+1))continue;
        int l=1,r=len;
        while(l<=len&&s1[l]==s2[l])++l;
        while(r>=1&&s1[r]==s2[r])--r;
        if(l>r)continue;
        ll hsh=0;
        for(int j=l;j<=r;++j){
            hsh=((__int128)hsh*bas+s1[j])%mod;
        }
        for(int j=l;j<=r;++j){
            hsh=((__int128)hsh*bas+s2[j])%mod;
        }
        for(int j=l-1;j>=1;--j)str1[i].push_back(s1[j]);
        for(int j=r+1;j<=len;++j)str2[i].push_back(s1[j]);
        que[i]=make_pair(hsh,i);
    }
    sort(que+1,que+n+m+1);
    for(int T=1;T<=n+m;){
        int l=T,r=T;
        while(r<n+m&&que[l].first==que[r+1].first)++r;
        cnt=0;
        root1=newNode();root2=newNode();
        for(int i=l;i<=r;++i){
            int x=que[i].second;
            if(x>n)continue;
            int t1=insert(root1,0,str1[x]);
            int t2=insert(root2,0,str2[x]);
            vc[t1].push_back(make_pair(0,t2));
        }
        for(int i=l;i<=r;++i){
            int x=que[i].second;
            if(x<=n)continue;
            int t1=fd(root1,0,str1[x]);
            int t2=fd(root2,0,str2[x]);
            vc[t1].push_back(make_pair(x-n,t2));
        }
        ct=0;
        dfs(root2);
        dfs_(root1);
        T=r+1;
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<'\n';
    return 0;
}