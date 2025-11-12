#include<bits/stdc++.h>
using namespace std;
string s,ta,tb;
int cnt;
struct trie
{
    int nxt[26],fail;
    int v;
}t[5000005];
int dep[5000005],fail[5000005][23],maxx[5000005];
long long v[5000005][23];
void build()
{
    int now=0;
    for(int i=0;i<s.size();i++)
    {
        if(!t[now].nxt[s[i]-'a'])
        {
            t[now].nxt[s[i]-'a']=++cnt;
            dep[cnt]=dep[now]+1;
        }
        now=t[now].nxt[s[i]-'a'];
    }
    t[now].v++;
}
int qu[5000005],cnt3;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        for(int j=0;j<ta.size();j++)
        {
            s+=ta[j];
            s+=tb[j];
        }
        build();
        s.clear();
    }
    qu[++cnt3]=0;
    for(int i=1;i<=cnt3;i++)
    {
        int x=qu[i];
        for(int i=0;i<26;i++)
        {
            if(t[x].nxt[i])
            {
                qu[++cnt3]=t[x].nxt[i];
                if(x) t[t[x].nxt[i]].fail=t[t[x].fail].nxt[i];
            }
            else t[x].nxt[i]=t[t[x].fail].nxt[i];
        }
        v[x][0]=t[t[x].fail].v;
        fail[x][0]=t[x].fail;
        for(int i=1;i<=22;i++)
        {
            v[x][i]=v[x][i-1]+v[fail[x][i-1]][i-1];
            fail[x][i]=fail[fail[x][i-1]][i-1];
            if(fail[x][i]==0)
            {
                maxx[x]=i;
                break;
            }
        }
    }
    while(q--)
    {
        cin>>ta>>tb;
        int l=-1,r=0;
        for(int i=0;i<ta.size();i++)
        {
            if(ta[i]!=tb[i])
            {
                if(l==-1) l=i*2;
                r=i*2;
            }
            s+=ta[i];
            s+=tb[i];
        }
        long long ans=0;
        int now=0,nxt1,nxt2;
        for(int i=0;i<s.size();i+=2)
        {
            nxt1=t[now].nxt[s[i]-'a'];
            nxt2=t[nxt1].nxt[s[i+1]-'a'];
            int c=i-l;
            if(i<=r||dep[now]<c)
            {
                now=nxt2;
                continue;
            }
            ans+=t[now].v;
            int now2=now;
            for(int j=maxx[now];j>=0;j--)
            {
                if(dep[fail[now2][j]]>=c)
                {
                    ans+=v[now2][j];
                    now2=fail[now2][j];
                    j=min(j,maxx[now2]+1);
                }
            }
            now=nxt2;
        }
        int c=s.size()-l;
        if(dep[now]>=c)
        {
            ans+=t[now].v;
            int now2=now;
            for(int j=maxx[now];j>=0;j--)
            {
                if(dep[fail[now2][j]]>=c)
                {
                    ans+=v[now2][j];
                    now2=fail[now2][j];
                    j=min(j,maxx[now2]+1);
                }
            }
        }
        s.clear();
        cout<<ans<<"\n";
    }
    return 0;
}
