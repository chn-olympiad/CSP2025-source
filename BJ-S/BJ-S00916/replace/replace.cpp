#include<bits/stdc++.h>
using namespace std;
int n,q,ans,cnt;
vector<int> b[10000005],c[10000005];
string s1,s2,s11[1005],s22[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n<=1000)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>s11[i]>>s22[i];
        }
        while(q--)
        {
            ans=0;
            cin>>s1>>s2;
            for(int i=0;i<s1.length();i++)
            {
                if(s1[i]!=s2[i])
                {
                    cnt=i;
                    break;
                }
            }
            for(int i=1;i<=n;i++)
            {
                int cnt1=s1.find(s11[i]);
                if(cnt1>cnt)
                {
                    continue;
                }
                if(cnt1<s1.length())
                {
                    string s3;
                    for(int j=0;j<s1.length();j++)
                    {
                        s3[j]=s1[j];
                    }
                    for(int j=0;j<s22[i].length();j++)
                    {
                        s3[j+cnt1]=s22[i][j];
                    }
                    bool flag=1;
                    for(int j=0;j<s1.length();j++)
                    {
                        if(s3[j]!=s2[j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        int cnt1=s1.find("b");
        int cnt2=s2.find("b");
        b[cnt1-cnt2+5000000].push_back(cnt1);
        c[cnt1-cnt2+5000000].push_back(s1.length()-cnt1);
    }
    while(q--)
    {
        cin>>s1>>s2;
        int cnt1=s1.find("b");
        int cnt2=s2.find("b");
        int id=cnt1-cnt2+5000000;
        ans=0;
        for(int i=0;i<b[id].size();i++)
        {
            if(cnt1>=b[id][i]&&s1.length()-cnt1>=c[id][i])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
