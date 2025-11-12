#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;
const int N=2e5+10;
string s[N];
int lmt[N];
int ans[N];
const ull base=131;
namespace ACAM
{
    const int N=5e6+10;
    int ch[N][26],cnt,fail[N];
    int nxt[N];//存边
    int head[N];
    int v;
    void insert(string s,int id)
    {
        int p=0;
        for(int i=0;i<s.size();i++)
        {
            int c=s[i]-'a';v=max(v,c);
            if(!ch[p][c]) ch[p][c]=++cnt;
            p=ch[p][c];
        }
        nxt[id]=head[p],head[p]=id;
        // cerr<<p<<' '<<id<<'\n';
    }
    struct edge{int to,nxt;}e[N];
    int head2[N],cnt2;
    void link(int x,int y)
    {
        e[++cnt2]={y,head2[x]};
        head2[x]=cnt2;
    }
    int qq[N];
    void build()
    {
        int r=0;
        for(int i=0;i<=v;i++) if(ch[0][i]) qq[++r]=ch[0][i];
        for(int i=1;i<=r;i++)
        {
            int x=qq[i];
            for(int i=0;i<=v;i++)
                if(ch[x][i]) 
                {
                    fail[ch[x][i]]=ch[fail[x]][i];
                    qq[++r]=ch[x][i];
                }
                else ch[x][i]=ch[fail[x]][i];
        }
        for(int i=1;i<=cnt;i++) link(fail[i],i);
    }
    struct node
    {
        ull h;
        int id,nxt;
    }ask[N];
    int head3[N],cnt3;
    void push(int x,int id,ull h)
    {
        ask[++cnt3]={h,id,head3[x]};
        head3[x]=cnt3;
    }
    gp_hash_table<ull,int> mp;
    void upd(int x,int v)
    {
        for(int i=head[x];i;i=nxt[i])
        {
            ull h=0,now=1;
            for(int j=s[i].size()-1;j>=0;j--,now=now*base)
            {
                h+=now*s[i][j];
                if(j<=lmt[i]) mp[h]+=v;
            }
        }
    }
    void work(int x)
    {
        upd(x,1);
        for(int i=head3[x];i;i=ask[i].nxt)
            if(mp.find(ask[i].h)!=mp.end())
                ans[ask[i].id]+=mp[ask[i].h];
        for(int i=head2[x];i;i=e[i].nxt) work(e[i].to);
        upd(x,-1);
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s1;
        cin>>s1>>s[i];
        int p=0;
        while(p<s1.size()&&s1[p]==s[i][p]) p++;
        if(p<s1.size())
        {
            lmt[i]=p;
            ACAM::insert(s1,i);
        }
    }
    ACAM::build();
    for(int id=1;id<=q;id++)
    {
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) continue;
        int m=t1.size();t1=' '+t1,t2=' '+t2;
        int p1=1,p2=m;
        while(t1[p1]==t2[p1]) p1++;
        while(t1[p2]==t2[p2]) p2--;
        int p=0;
        ull h=0;
        for(int i=1;i<=m;i++)
        {
            p=ACAM::ch[p][t1[i]-'a'];
            if(i>=p1) h=h*base+t2[i];
            if(i>=p2) ACAM::push(p,id,h);
        }
    }
    ACAM::work(0);
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
    return 0;
}