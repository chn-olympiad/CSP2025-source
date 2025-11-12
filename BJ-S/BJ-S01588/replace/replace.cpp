#include<bits/stdc++.h>
using namespace std;
const int M=5000005;
const int N=400005;
int n,q;
struct ACATM
{
    int nex[M][27],cnt;
    int len[M],fail[M],dfn[M],sz[M];
    int fir[M],nxx[2*M],to[2*M],tt,tot;
    void clear()
    {
        memset(nex,0,sizeof(nex));
        memset(len,0,sizeof(len));
        memset(fail,0,sizeof(fail));
        memset(fir,0,sizeof(fir));
        cnt=0;tt=0,tot=0;
    }
    void ist(int u,int v)
    {
        nxx[++tt]=fir[u];
        fir[u]=tt;
        to[tt]=v;
    }
    int insert(string &a)
    {
        int u=0;
        for(int i=0;i<a.size();i++)
        {
            int cc=a[i]-'a';
            if(nex[u][cc]==0)nex[u][cc]=++cnt,len[cnt]=i+1;
            u=nex[u][cc];
        }
        return u;
    }
    void build()
    {
        queue<int>q;
        for(int i=0;i<26;i++)
        {
            if(nex[0][i])q.push(nex[0][i]);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            //cerr<<u<<"??\n";
            for(int j=0;j<26;j++)
            {
                if(nex[u][j])
                {
                    fail[nex[u][j]]=nex[fail[u]][j];
                    q.push(nex[u][j]);
                }
                else
                {
                    nex[u][j]=nex[fail[u]][j];
                }
            }
        }
    }
    void dfs(int u)
    {
		//cerr<<u<<"???\n";
        dfn[u]=++tot;
        sz[u]=1;
        for(int i=fir[u];i;i=nxx[i])
        {
            int v=to[i];
            dfs(v);
            sz[u]+=sz[v];
        }
    }
}aa,bb;

vector<pair<int,int> >qq[M],qp[M];
int ida[N],idb[N];
long long ans[N];
int c[M];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
    for(int i=x;i<=bb.tot;i+=lowbit(i))
    {
        c[i]+=y;
    }
}
int get(int x)
{
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
    {
        ans+=c[i];
    }
    return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    aa.clear();bb.clear();
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        ida[i]=aa.insert(a);
        idb[i]=bb.insert(b);
        //cerr<<ida[i]<<' '<<idb[i]<<"??\n";
    }
    aa.build();
    
    bb.build();
    //cerr<<"!!\n";
    for(int i=1;i<=aa.cnt;i++)
    {
		
        aa.ist(aa.fail[i],i);
    }

    for(int i=1;i<=bb.cnt;i++)
    {
        bb.ist(bb.fail[i],i);
    }
    
    aa.dfs(0);
    
    bb.dfs(0);
    //cerr<<"!!\n";
    for(int i=1;i<=q;i++)
    {
        string a,b;
        cin>>a>>b;
        if(a.size()!=b.size())continue;
        int ll=-1,rr=-1;
        for(int j=0;j<a.size();j++)
        {
            if(a[j]!=b[j])
            {
                if(ll==-1)ll=j;
                rr=j;
            }
        }
        if(ll==-1)
        {
            int ua=0,ub=0;
            for(int j=0;j<a.size();j++)
            {
                ua=aa.nex[ua][a[j]-'a'];
                ub=bb.nex[ub][b[j]-'a'];
                qq[aa.dfn[ua]].push_back({i,bb.dfn[ub]});
            }
        }
        else
        {
            int ua=0,ub=0;
            int tp=0;
            for(int j=0;j<a.size();j++)
            {
                ua=aa.nex[ua][a[j]-'a'];
                ub=bb.nex[ub][b[j]-'a'];
                tp=aa.nex[tp][a[j]-'a'];
                if(j>=rr&&(j-aa.len[ua]+1)<=ll&&(j-bb.len[ub]+1)<=ll)
                {
                    qq[aa.dfn[ua]].push_back({i,bb.dfn[ub]});

                    while((j-aa.len[tp]+1)<=ll)tp=aa.fail[tp];
                    qq[aa.dfn[tp]].push_back({-i,bb.dfn[ub]});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
		//cerr<<aa.dfn[ida[i]]<<' '<<aa.dfn[ida[i]]+aa.sz[ida[i]]<<' '<<bb.dfn[idb[i]]<<' '<<bb.dfn[idb[i]]+bb.sz[idb[i]]<<"??\n";
        qp[aa.dfn[ida[i]]].emplace_back(bb.dfn[idb[i]],1);
        qp[aa.dfn[ida[i]]].emplace_back(bb.dfn[idb[i]]+bb.sz[idb[i]],-1);
        qp[aa.dfn[ida[i]]+aa.sz[ida[i]]].emplace_back(bb.dfn[idb[i]],-1);
        qp[aa.dfn[ida[i]]+aa.sz[ida[i]]].emplace_back(bb.dfn[idb[i]]+bb.sz[idb[i]],1);
    }
    for(int i=1;i<=aa.tot;i++)
    {
        for(auto x:qp[i])
        {
            add(x.first,x.second);
            //cerr<<i<<' '<<x.first<<' '<<x.second<<"??\n";
        }
        //cerr<<get(12)<<"!!\n";
        for(auto x:qq[i])
        {
            if(x.first>0)ans[x.first]+=get(x.second);
            else ans[-x.first]-=get(x.second);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i]<<'\n';
    }
}
