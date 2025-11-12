#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string a[200005][3],s1,s2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    while(m--)
    {
        ans=0;
        cin>>s1>>s2;
        if(s1.size()!=s2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(s1.find(a[i][1])!=-1)
            {
                string s3="";
                for(int j=0;j<s1.find(a[i][1]);j++)
                {
                    s3=s3+s1[j];
                }
                s3+=a[i][2];
                for(int j=s1.find(a[i][1])+a[i][2].size();j<s1.size();j++)
                {
                    s3=s3+s1[j];
                }
                if(s3==s2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
