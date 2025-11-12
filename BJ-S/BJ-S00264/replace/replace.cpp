#include<bits/stdc++.h>
using namespace std;
struct stu{
    string b;
    string x;
}a[200005];
int main()
{

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i].b;
        cin>>a[i].x;
    }
    for(long long _=1;_<=q;_++)
    {
        long long ans=0;
        string s,t;
        cin>>s;
        cin>>t;
        long long l=s.size();
        for(long long i=0;i<=l;i++)
        {
            for(long long j=0;j<=l;j++)
            {
                if(i+j<=l)
                {
                    int k=l-i-j;
                    string x1;
                    string y1;
                    string z1;

                    for(long long ii=0;ii<i;ii++)
                    {
                        x1+=s[ii];
                    }
                    for(long long jj=i;jj<i+j;jj++)
                    {
                        y1+=s[jj];
                    }
                    for(long long kk=i+j;kk<l;kk++)
                    {
                        z1+=s[kk];
                    }
                    for(long long p=1;p<=n;p++)
                    {
                        if(y1==a[p].b)
                        {
                            string y2=y1;
                            y2=a[p].x;
                            string ss=x1+y2+z1;
                            if(ss==t)
                            {
                                ans++;
                            }
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }




    return 0;
}

