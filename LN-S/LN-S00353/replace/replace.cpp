#include <bits/stdc++.h>
using namespace std;
#define piii pair<int,pair<int,int> >
#define fi first
#define se second
#define endl '\n'
//#define int long long
int T=1,n,q;
map<int,vector<pair<string,string> > > v;
vector<int> vv;
void solve()
{
    cin>>n>>q;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        v[(int)s2.size()-(int)s1.size()].push_back({s1,s2});
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int len=(int)t1.size()-(int)t2.size();
        //v->len
        ans=0;
        for(auto xx:v[len])
        {
            string s1=xx.fi,s2=xx.se;
            if(s1.size()>t1.size()||s2.size()>t2.size())continue;
            //cout<<t1<<" "<<t2<<" "<<s1<<" "<<s2<<endl;//
            vv.clear();
            bool item=0;
            string st="";
            for(int i=0;i<t1.size();i++)
            {
                bool flog=0;
                if(t1[i]==t2[i])
                {
                    st+=t1[i];
                  // cout<<st<<endl;///
                    continue;
                }
                else if(item==1)
                {
                    st+=t1[i];
                   // cout<<st<<endl;//
                    continue;
                }
                else if(t1[i]!=t2[i])
                {
                    for(int j=0;j<s1.size();j++)
                    {
                        if(s1[j]==t1[i])vv.push_back(i-j);
                    }
                }
            }
            for(auto id:vv)
            {
                string st="";
                for(int i=0;i<id;i++)st+=t1[i];
                st+=s2;
                for(int i=id+(int)s1.size();i<t1.size();i++)st+=t1[i];
                bool haha=0;
                for(int i=0;i<t2.size();i++)
                {
                    if(st[i]!=t2[i])
                    {
                        haha=1;
                        break;
                    }
                }
                if(haha==0)
                {
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //cin>>T;
    for(int e=1;e<=T;e++)solve();
    return 0;
}
