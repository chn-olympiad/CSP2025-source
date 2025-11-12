#include <bits/stdc++.h>
using namespace std;
long long n,q,le=-1,ri=-1,sum;
string a1,a2;
struct child
{
    string s1,s2;
    long long len,z,y;
};
child s[200006];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].s1;
        cin>>s[i].s2;
        s[i].len=s[i].s1.size();
        s[i].z=-1;
        s[i].y=-1;
        for(int j=0;j<s[i].len;j++)
        {
            if(s[i].s1[j]!=s[i].s2[j])
            {
                if(s[i].z==-1)
                {
                    s[i].z=j;
                }
                else
                {
                    s[i].y=j;
                }
            }
            if(s[i].y==-1)
            {
                s[i].y=s[i].z;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        sum=0;
        le=-1;
        ri=-1;
        cin>>a1>>a2;
        if(a1.size()!=a2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<a1.size();j++)
        {
            if(a1[j]!=a2[j])
            {
                if(le==-1)
                {
                    le=j;
                }
                else
                {
                    ri=j;
                }
            }
            if(ri==-1)
            {
                ri=le;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(s[j].y-s[j].z==ri-le)
            {
                long long cha=le-s[j].z;
                bool flag=0;
                for(int k=0;k<s[j].len;k++)
                {
                    if(s[j].s1[k]==a1[k+cha]&&s[j].s2[k]==a2[k+cha])
                    {
                        continue;
                    }
                    flag=1;
                    break;
                }
                if(!flag)
                {
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
