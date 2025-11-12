#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,q;
string s1[200005],s2[200005];
vector<int> p[30];
int check(string t1,string t2)
{
    if(t1.size()!=t2.size()) return 0;
    int res=0,l=-1,r=-1;
    for(int i=0;i<t1.size();i++)
    {
        if(t1[i]!=t2[i])
        {
            if(l==-1) l=r=i;
            else r=i;
        }
    }
    //cout<<l<<' '<<r<<endl;
    for(int i=0;i<t1.size();i++)
    {
        int c=t1[i]-'a';
        //cout<<c<<endl;
        if(l>=0&&i>l) break;
        if(p[c].size())
        {
            for(int j=0;j<p[c].size();j++)
            {
                int w=p[c][j],l0=i,r0=0;
                //cout<<w<<endl;
                while(l0<t1.size()&&r0<s1[w].size())
                {
                    if(t1[l0]!=s1[w][r0]) break;
                    if(t2[l0]!=s2[w][r0]) break;
                    l0++,r0++;
                }
                if(l0>r&&r0==s1[w].size()) res++;
            }
        }
    }
    return res;
}
signed main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        p[s1[i][0]-'a'].push_back(i);
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        cout<<check(t1,t2)<<endl;
    }
    return 0;
}
