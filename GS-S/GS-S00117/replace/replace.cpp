#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

struct node{
    string s;
    ll len;
};

node a[200050][2];

int n,q;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0].s>>a[i][1].s;
    }
    while(q--)
    {
       ll ans=0;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s1[i]==a[j][0].s[0])
                {
                    if(a[j][0].s==s1&&a[j][1].s==s2)
                    {
                        ans++;continue;
                    }
                    string cc,x,z;
                    if(a[j][0].s.size()<=s1.size()-i)
                    {
                         cc=s1.substr(i,i+a[j][0].s.size()-1);

                    x=s1.substr(0,i);
                   // cout<<x<<' ';
                     z=s1.substr(i+a[j][0].s.size());
                    //cout<<z<<' ';

                    }
                    else
                    {
                        continue;
                    }

                    if(cc==a[j][0].s)
                    {
                        if(x+a[j][1].s+z==s2) ans++;
                    }
                    //break;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
