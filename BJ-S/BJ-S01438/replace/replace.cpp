#include<bits/stdc++.h>
using namespace std;
long long ans;
int g[5000005],n,q;
vector<int> v1,v2;
string s[200005][3],t1,t2;
void kmp1(string x,string y)
{
    memset(g,0,sizeof(g));
    int l1=x.size(),l2=y.size();
    if (l2<l1)
    {
        return;
    }
    string tmp=x+"%"+y;
    for (int i=l1+1;i<=l1+l2;i++)
    {
        int tt=g[i-1];
        while (tmp[tt]!=tmp[i]&&tt>0)
        {
            tt=g[tt-1];
        }
        if (tmp[tt]==tmp[i])
        {
            tt++;
        }
        g[i]=tt;
        if (g[i]==l1)
        {
            v1.push_back(i-2*l1);
        }
    }
}
void kmp2(string x,string y)
{
    memset(g,0,sizeof(g));
    int l1=x.size(),l2=y.size();
    if (l2<l1)
    {
        return;
    }
    string tmp=x+"%"+y;
    for (int i=l1+1;i<=l1+l2;i++)
    {
        int tt=g[i-1];
        while (tmp[tt]!=tmp[i]&&tt>0)
        {
            tt=g[tt-1];
        }
        if (tmp[tt]==tmp[i])
        {
            tt++;
        }
        g[i]=tt;
        if (g[i]==l1)
        {
            v2.push_back(i-2*l1);
        }
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    while (q--)
    {
        cin>>t1>>t2;
        for (int i=1;i<=n;i++)
        {
            v1.clear();
            v2.clear();
            kmp1(s[i][1],t1);
            kmp2(s[i][2],t2);
            int p=0,qq=0;
            while (p<v1.size()&&qq<v2.size())
            {
                if (v1[p]==v2[qq])
                {
                    if (t1.substr(0,v1[p])!=t2.substr(0,v2[qq]))
                    {
                        break;
                    }
                    if (t1.substr(v1[p]+s[i][1].size(),t1.size()-1)!=t2.substr(v2[qq]+s[i][1].size(),t2.size()-1))
                    {
                        p++;
                        q++;
                        continue;
                    }
                    ans++;
                    p++;
                    qq++;
                }
                else if (v1[p]>v2[qq])
                {
                    qq++;
                }
                else
                {
                    p++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}