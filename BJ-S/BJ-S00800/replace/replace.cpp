#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e7+10,mod=1145142023,base=27;
int txt=0;
map<pair<int,int>,pair<int,int> >mp;
string s1,s2;
int book[N],f[N],tp;
struct trie
{
    int nxt[N][27];
    vector<int>v[N];
    void add(int id,string s,int y)
    {
        for(char c:s)
        {
            if(!nxt[id][c-'a'])nxt[id][c-'a']=++txt;
            id=nxt[id][c-'a'];
        }
        v[id].push_back(y);
    }
    void que(int id,string s)
    {
        for(char c:s)
        {
            for(int j:v[id])book[j]=1,f[++tp]=j;
            if(!nxt[id][c-'a'])return;
            id=nxt[id][c-'a'];
        }
        for(int j:v[id])book[j]=1,f[++tp]=j;
    }
    int query(int id,string s)
    {
        int res=0;
        for(char c:s)
        {
            for(int j:v[id])res+=book[j],book[j]=0;
            if(!nxt[id][c-'a'])return res;
            id=nxt[id][c-'a'];
        }
        for(int j:v[id])res+=book[j],book[j]=0;
        return res;
    }
}t1;
string s;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        tp=0;
        cin>>s1>>s2;
        if(s1==s2)continue;
        int len=s1.size(),l=len,r=0;
        for(int j=0;j<len;j++)
        {
            if(s1[j]!=s2[j])
            {
                l=j;break;
            }
        }
        for(int j=len-1;j>=0;j--)
        {
            if(s1[j]!=s2[j])
            {
                r=j;break;
            }
        }
        int p=0;
        for(int i=l;i<=r;i++)
        {
            p=(p*base+s1[i]-'a'+1)%mod;
        }
        int q=0;
        for(int i=l;i<=r;i++)
        {
            q=(q*base+s2[i]-'a'+1)%mod;
        }
        if(!mp.count(make_pair(p,q)))mp[make_pair(p,q)]=make_pair(++txt,++txt);
        s="";
        for(int i=l-1;i>=0;i--)s=s+s1[i];
        t1.add(mp[make_pair(p,q)].first,s,i);
        s="";
        for(int i=r+1;i<len;i++)s=s+s1[i];
        t1.add(mp[make_pair(p,q)].second,s,i);
    }
    while(q--)
    {
        cin>>s1>>s2;
        if(s1==s2)continue;
        int len=s1.size(),l=len,r=0;
        for(int j=0;j<len;j++)
        {
            if(s1[j]!=s2[j])
            {
                l=j;break;
            }
        }
        for(int j=len-1;j>=0;j--)
        {
            if(s1[j]!=s2[j])
            {
                r=j;break;
            }
        }
        int p=0;
        for(int i=l;i<=r;i++)
        {
            p=(p*base+s1[i]-'a'+1)%mod;
        }
        int q=0;
        for(int i=l;i<=r;i++)
        {
            q=(q*base+s2[i]-'a'+1)%mod;
        }
        if(!mp.count(make_pair(p,q)))
        {
            cout<<"0\n";
            continue;
        }
        s="";
        for(int i=l-1;i>=0;i--)s=s+s1[i];
        t1.que(mp[make_pair(p,q)].first,s);
        s="";
        for(int i=r+1;i<len;i++)s=s+s1[i];
        cout<<t1.query(mp[make_pair(p,q)].second,s)<<endl;
        while(tp)
        {
            // cout<<f[tp]<<' ';
            book[f[tp]]=0,tp--;
        }
        // cout<<endl;
    }
    return 0;
}