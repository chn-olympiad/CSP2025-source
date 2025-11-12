#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string a,b;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    while(q--)
    {
        int ans=0;
        int st=-1,ed=-1;
        cin>>a>>b;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i] && ed==-1)
            {
                st=i;
                ed=i;
            }
            if(a[i]!=b[i])
            {
                ed=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=a.size()-s1[i].size()+1;j++)
            {
                string k;
                if(a.substr(j,s1[i].size())==s1[i])
                {
                    k=a.substr(0,j)+s2[i]+a.substr(j+s1[i].size(),a.length()-j-s1[i].size());
                    if(k==b)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
