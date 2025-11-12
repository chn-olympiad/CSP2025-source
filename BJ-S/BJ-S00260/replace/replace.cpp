#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int a[100005],s[100005],b[100005];
    int zuo1[100005],you1[100005],zuo2[100005],you2[100005];
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        s[i]=s1.size();
        for(int j=0;j<max(s1.size(),s2.size());j++)
        {
            if(s1[j]=='b')
            {
                a[i]=j+1;
                zuo1[i]=j;
                you1[i]=s1.size()-j;
            }

            if(s2[j]=='b')
            {
                 b[i]=j+1;
                 zuo2[i]=j;
                 you2[j]=s2.size()-j;
            }

        }
    }
    int c[100005],d[100005];
    for(int i=1;i<=q;i++)
    {
        string q1,q2;
        cin>>q1>>q2;
        int x,y,l,r;
        int ans=0;
        for(int j=0;j<max(q1.size(),q2.size());j++)
        {
            if(q1[j]=='b')
            {
                x=j+1;
                l=j;
                r=q1.size()-j;
            }

            if(q2[j]=='b')
            {
                y=j+1;

            }

        }
        for(int j=1;j<=n;j++)
        {
            if(a[j]-b[j]==x-y && zuo1[j]<=l &&you1[j]<=r)
                ans++;

        }
        cout<<ans<<endl;
    }
    return 0;
}
