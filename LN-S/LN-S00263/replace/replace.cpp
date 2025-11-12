#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int V=8e6+5;
int n,q,cnt,tot;
map<string,int> mp;
int tr[V][27],rt[N],tg[V],fail[V];
void ins(int r,string t)
{
    int u=r;
    for(int i=0;i<t.length();i++)
    {
        const int c=t[i]-'a';
        if(!tr[u][c])tr[u][c]=++tot;
        u=tr[u][c];
    }tg[u]++;
}void build(int r)
{
    queue<int> q;
    for(int c=0;c<27;c++)
    if(!tr[r][c])tr[r][c]=r;
    else q.push(tr[r][c]),fail[tr[r][c]]=r;
    while(q.size())
    {
        int u=q.front();q.pop();
        tg[u]+=tg[fail[u]];
        for(int c=0;c<27;c++)
        {
            if(!tr[u][c]){tr[u][c]=tr[fail[u]][c];}
            else {fail[tr[u][c]]=tr[fail[u]][c];q.push(tr[u][c]);}
        }
    }
}int query(int r,string s)
{
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        r=tr[r][s[i]-'a'];
        ans+=tg[r];
    }return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;for(int i=1;i<=n;i++)
    {
        string x,y;cin>>x>>y;
        int d=x.length();
        int l=0,r=d-1;
        while(l<d&&x[l]==y[l])l++;
        if(l==d)continue;
        while(x[r]==y[r])r--;
        string s="";
        for(int i=l;i<=r;i++)s+=x[i];
        for(int i=l;i<=r;i++)s+=y[i];
        if(mp.find(s)==mp.end())
        {mp[s]=++cnt;rt[cnt]=++tot;}
        string t="";
        for(int i=0;i<l;i++)t+=x[i];
        t+='{';
        for(int i=r+1;i<d;i++)t+=x[i];
        ins(rt[mp[s]],t);
    }for(int i=1;i<=cnt;i++)build(rt[i]);
    for(int i=1;i<=q;i++)
    {
        string x,y;cin>>x>>y;
        int d=x.length();
        int l=0,r=d-1;
        while(x[l]==y[l])l++;
        while(x[r]==y[r])r--;
        string s="";
        for(int i=l;i<=r;i++)s+=x[i];
        for(int i=l;i<=r;i++)s+=y[i];
        string t="";
        for(int i=0;i<l;i++)t+=x[i];
        t+='{';
        for(int i=r+1;i<d;i++)t+=x[i];
        if(mp.find(s)==mp.end())cout<<"0\n";
        else cout<<query(rt[mp[s]],t)<<'\n';
    }return 0;
}
