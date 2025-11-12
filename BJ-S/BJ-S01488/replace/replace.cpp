#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;
string s1,s2,s3,s4;
int n,q,ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while (q--)
    {
        ans=0;
        cin>>s1>>s2;
        if (s1.size()!=s2.size())
        {
            cout<<0<<endl;
            break;
        }
        int start,end;
        for (int i=0;i<s1.size();i++)
            if (s1[i]!=s2[i])
            {
                start=i;
                break;
            }
        for (int i=s1.size()-1;i>=0;i--)
            if (s1[i]!=s2[i])
            {
                end=i;
                break;
            }
        s3=s1;s4=s2;
        int x=s1.size()-end;
        for (int i=0;i<=start;i++)
        {
            s3.erase(s3.size()-x,x);s4.erase(s4.size()-x,x);
            for (int j=end;j<s1.size();j++)
            {
                s3+=s1[j];s4+=s2[j];
                auto it=mp.find(s3);
                if (it!=mp.end())
                    if (mp[s3]==s4)
                        ans++;
            }
            s3.erase(0,1);s4.erase(0,1);
        }
        cout<<ans<<endl;
    }
}