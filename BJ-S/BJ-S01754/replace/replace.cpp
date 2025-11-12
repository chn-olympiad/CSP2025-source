#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
void solve()
{
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    string x,y;
    int ans=0,l,r;
    while(q--)
    {
        ans=0;
        l=200005,r=-1;
        cin>>x>>y;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]!=y[i])
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(l==200005 && r==-1)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int k=1;k<=n;k++)
        {
            if(x.size()<s1[k].size())
                continue;
            for(int i=0;i<x.size();i++)
            {
                if(x[i]==s1[k][0])
                {
                    bool f=true;
                    for(int j=0;j<s1[k].size();j++)
                    {
                        if(x[i+j]!=s1[k][j] || y[i+j]!=s2[k][j])
                            f=false;
                    }
                    if(f && i<=l && i+s1[k].size()-1>=r)
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
int l[500005],r[500005];
void solveB()
{
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        int ss1=s1[i].find('b');
        int ss2=s2[i].find('b');
        if(ss1<=ss2)
            r[ss2-ss1]++;
        else
            l[ss1-ss2]++;
    }
    string x,y;
    while(q--)
    {
        cin>>x>>y;
        int ss1=x.find('b');
        int ss2=y.find('b');
        if(ss1>ss2)
            cout<<r[ss2-ss1]<<endl;
        else
            cout<<l[ss1-ss2]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n<=1000)
        solve();
    else
        solveB();
    return 0;
}
