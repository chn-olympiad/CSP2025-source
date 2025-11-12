#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pow power
using namespace std;
template<typename T>void read(T &x)
{
    x=0;
    int fl=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=fl;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=2e5+5,M=5e6+5,mod=998244353,p=13331;
int pls(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int mns(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1ll*x*y%mod;}
int trie[M][26];
int dtot,tot;
int dfn[M],ed[M];
int insert(string &s)
{
    // cout<<"string: "<<s<<endl;
    int x=0;
    for(char v:s)
    {
        v-='a';
        if(!trie[x][v]) trie[x][v]=++tot;
        x=trie[x][v];
    }
    return x;
}
void dfs(int x)
{
    dfn[x]=++dtot;
    for(int i=0;i<26;i++)
        if(trie[x][i])
            dfs(trie[x][i]);
    ed[x]=dtot;
}
void clear()
{
    for(int i=0;i<=tot;i++) dfn[i]=ed[i]=0;
    dtot=0;
    for(int i=0;i<=tot;i++) memset(trie[i],0,sizeof(trie[i]));
    tot=0;
}
int valq1[N],vala1l[N],vala1r[N];
int valq2[N],vala2l[N],vala2r[N];
int ans[N];
int n,m;
pair<string,string> an[N],qn[N]; 
unordered_map<int,vector<int> > qry,info;
int q[N],qlen;
int a[N],alen;
namespace BIT
{
    int c[M];
    int lowbit(int x){return x&-x;}
    void add(int x,int val){for(;x<=dtot;x+=lowbit(x)) c[x]+=val;}
    void add(int l,int r,int val){add(l,val);add(r+1,-val);}
    int query(int x){int res=0;for(;x>=1;x-=lowbit(x)) res+=c[x];return res;}
    void clear(){for(int i=1;i<=dtot;i++) c[i]=0;}
}
vector<pair<int,int> > vec[M];
void solve(int hsh)
{
    if(!info.count(hsh)) return ;
    qlen=0;alen=0;
    vector<int> vtmp=qry[hsh];
    for(int v:vtmp) q[++qlen]=v;
    vtmp=info[hsh];
    for(int v:vtmp) a[++alen]=v;
    // cout<<hsh<<"____________"<<endl;
    // for(int i=1;i<=alen;i++) cout<<a[i]<<" ";cout<<endl;
    // for(int i=1;i<=qlen;i++) cout<<q[i]<<" ";cout<<endl;
    clear();
    for(int i=1;i<=qlen;i++) valq1[i]=insert(qn[q[i]].first);
    for(int i=1;i<=alen;i++) vala1l[i]=insert(an[a[i]].first);
    dfs(0);
    for(int i=1;i<=qlen;i++) valq1[i]=dfn[valq1[i]];
    for(int i=1;i<=alen;i++) vala1r[i]=ed[vala1l[i]],vala1l[i]=dfn[vala1l[i]];
    int up=dtot;
    clear();
    for(int i=1;i<=qlen;i++) valq2[i]=insert(qn[q[i]].second);
    for(int i=1;i<=alen;i++) vala2l[i]=insert(an[a[i]].second);
    dfs(0);
    for(int i=1;i<=qlen;i++) valq2[i]=dfn[valq2[i]];
    for(int i=1;i<=alen;i++) vala2r[i]=ed[vala2l[i]],vala2l[i]=dfn[vala2l[i]];
    // cout<<"part1"<<endl;
    // for(int i=1;i<=alen;i++) cout<<i<<" "<<vala1l[i]<<" "<<vala1r[i]<<" "<<vala2l[i]<<" "<<vala2r[i]<<endl;
    // for(int i=1;i<=qlen;i++) cout<<i<<" "<<valq1[i]<<" "<<valq2[i]<<endl;

    // int tmp=0;
    // for(int i=1;i<=alen;i++) if(vala1l[i]<=161&&161<=vala1r[i]&&vala2l[i]<=7661&&7661<=vala2r[i]) tmp++;
    // cout<<"cur"<<tmp<<endl;
    BIT::clear();
    for(int i=1;i<=up;i++) vec[i].clear();
    for(int i=1;i<=alen;i++) vec[vala1l[i]].push_back(make_pair(1,i)),vec[vala1r[i]+1].push_back(make_pair(-1,i));
    for(int i=1;i<=qlen;i++) vec[valq1[i]].push_back(make_pair(0,i));
    for(int i=1;i<=up;i++)
        for(auto v:vec[i])
        {
            int id=v.second,opt=v.first;
            if(opt==0) ans[q[id]]=BIT::query(valq2[id]);
            else BIT::add(vala2l[id],vala2r[id],opt);
        }
}
// 161 7661
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int d=1;d<=n;d++)
    {
        string s,t;
        cin>>s>>t;
        if(s==t) continue;
        int i=0,j=s.length()-1;
        while(s[i]==t[i]) i++;
        while(s[j]==t[j]) j--;
        string s1="",s2="",s3="",s4="";
        for(int k=0;k<i;k++) s1.push_back(s[k]);
        for(int k=i;k<=j;k++) s2.push_back(s[k]);
        for(int k=i;k<=j;k++) s4.push_back(t[k]);
        for(int k=j+1;k<s.length();k++) s3.push_back(s[k]);
        int hsh=0;
        for(char v:s2) hsh=pls(mul(hsh,p),v);
        hsh=pls(mul(hsh,p),'#');
        for(char v:s4) hsh=pls(mul(hsh,p),v);
        reverse(s1.begin(),s1.end());
        // reverse(s3.begin(),s3.end());
        an[d]=make_pair(s1,s3);
        info[hsh].push_back(d);
        // cout<<hsh<<endl;
        // if(hsh==691225253) cout<<hsh<<" "<<s1<<" "<<s3<<endl;
    }
    for(int d=1;d<=m;d++)
    {
        string s,t;
        cin>>s>>t;
        if(s.length()!=t.length()) continue;
        int i=0,j=s.length()-1;
        while(s[i]==t[i]) i++;
        while(s[j]==t[j]) j--;
        string s1="",s2="",s3="",s4="";
        for(int k=0;k<i;k++) s1.push_back(s[k]);
        for(int k=i;k<=j;k++) s2.push_back(s[k]);
        for(int k=i;k<=j;k++) s4.push_back(t[k]);
        for(int k=j+1;k<s.length();k++) s3.push_back(s[k]);
        int hsh=0;
        for(char v:s2) hsh=pls(mul(hsh,p),v);
        hsh=pls(mul(hsh,p),'#');
        for(char v:s4) hsh=pls(mul(hsh,p),v);
        reverse(s1.begin(),s1.end());
        // reverse(s3.begin(),s3.end());
        qn[d]=make_pair(s1,s3);
        qry[hsh].push_back(d);
        // cout<<hsh<<" "<<s1<<" "<<s3<<endl;
    }
    for(auto &v:qry) solve(v.first);
    for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
    return 0;
}
// g++ replace.cpp -o replace -std=c++14 -O2 -static -Wall -Wextra 
// g w 336771133
// 774757402
// 28 691225253