#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++)
    {
        string s,t;
        int ans=0;
        cin>>s>>t;
        for(int i=1;i<=n;i++)
        {
            size_t p=0;
            while((p=s.find(s1[i],p))!=string::npos)
            {
                string ss=s;
                for(int j=p;j<p+s1[i].size();j++)
                    ss[j]=s2[i][j-p];
                if(ss==t)
                    ans++;
                p++;
            }
        }
        cout<<ans<<'\n';
    }
}