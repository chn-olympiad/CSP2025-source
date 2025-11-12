#include<bits/stdc++.h>
#define int long long
const int base=131,mod=998244353; 
using namespace std;
int n,_,tot,ans,maxx;
string s,t;
struct node
{
    int a,b;
    bool operator <(const node &i)const
    {
        if(a^i.a) return a<i.a;
        return b<i.b;
    }
};
map<node ,int > mp;
int a[5000005],b[5000005],vis[5000005];
int get(string s)
{
    int now=0,len=s.size();
    for(int j=0;j<len;j++)
        now=(now*base%mod+(s[j]-'a'+1))%mod;
    return now;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>_;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>t;
        int x=get(s),y=get(t);
        mp[(node){x,y}]++;
        int len=s.size();
        vis[len]=1;
        maxx=max(maxx,len);
        if(x==y) tot++;
    }
    for(int i=1;i<=_;i++)
    {
        cin>>s>>t;
        int len=s.size(),ans=0,l=-1,r=-1;
        for(int j=0;j<len;j++)
            if(s[j]!=t[j])
            {
                if(l==-1) l=j;
                r=j;
            }
        for(int j=l;j>=0;j--)
            for(int k=r;k<len;k++)
            {
                int len=k-j+1;
                if(len>maxx) break;
                if(!vis[len]) continue;
                int x1=0,x2=0;
                for(int x=j;x<=k;x++)
                    x1=(x1*base%mod+s[x]-'a'+1)%mod,
                    x2=(x2*base%mod+t[x]-'a'+1)%mod;
                if(mp.find((node){x1,x2})!=mp.end()) ans+=mp[(node){x1,x2}];
            }
        if(l==-1) cout<<tot<<"\n";
        else cout<<ans<<"\n";
    }
}