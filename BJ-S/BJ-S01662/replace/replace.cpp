#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,q,sz[200005],b[200005][2];
multiset<pair<int,pii> > st;
string s[200005][2];

bool fl=1;

void solve()
{
    for(int i=1;i<=n;i++)
    {
        int d=b[i][0]-b[i][1];
        st.insert({d,{b[i][0],sz[i]-b[i][0]-1}});
    }
    while(q--)
    {
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<'\n';
            continue;
        }
        int len=t1.size(),ps1,ps2;
        for(int i=0;i<len;i++)
        {
            if(t1[i]=='b') ps1=i;
            if(t2[i]=='b') ps2=i;
        }
        auto L=st.lower_bound({ps1-ps2,{-2e9,-2e9}});
        auto R=st.upper_bound({ps1-ps2,{2e9,2e9}});
        for(auto it=L;it!=R;it++)
        {
            auto tp=(*it);
            if(tp.se.fi<=ps1&&tp.se.se<=len-ps1-1) ans++;
        }
        cout<<ans<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    long long sm=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        sz[i]=s[i][0].size();
        sm+=2*sz[i];
        if(!fl) continue;
        int ca=0,cb=0;
        for(int j=0;j<sz[i];j++)
        {
            if(s[i][0][j]=='a') ca++;
            if(s[i][0][j]=='b') b[i][0]=j,cb++;
        }
        if(ca+cb!=sz[i])
        {
            fl=0;
            continue;
        }
        if(cb!=1)
        {
            fl=0;
            continue;
        }
        for(int j=0;j<sz[i];j++)
        {
            if(s[i][1][j]=='a') ca--;
            if(s[i][1][j]=='b') b[i][1]=j,cb--;
        }
        if(ca!=0||cb!=0)
        {
            fl=0;
            continue;
        }
    }
    if(fl&&n>100&&q>100&&sm>200)
    {
        solve();
        return 0;
    }
    while(q--)
    {
        string t1,t2;
        int ans=0;
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(t1.find(s[i][0])==-1) continue;
            if(t2.find(s[i][1])==-1) continue;
            int x=t1.find(s[i][0]);
            int y=t2.find(s[i][1]);
            while(x!=y&&x!=-1&&y!=-1)
            {
                if(x<y)
                {
                    x=t1.find(s[i][0],x+1);
                    continue;
                }
                if(x>y)
                {
                    y=t2.find(s[i][1],y+1);
                    continue;
                }
                break;
            }
            if(t1.substr(0,x)!=t2.substr(0,y)) continue;
            if(t1.substr(x+sz[i])!=t2.substr(y+sz[i])) continue;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}



