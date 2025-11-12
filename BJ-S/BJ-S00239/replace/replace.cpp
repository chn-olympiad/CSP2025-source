#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010],t1[200010],t2[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(long long i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(long long i=1;i<=q;i++) cin>>t1[i]>>t2[i];
    for(long long i=1;i<=q;i++)
    {
        long long sy1,sy2;
        for(long long j=0;j<t1[i].size();j++)
        {
            if(t1[i][j]!=t2[i][j])
            {
                sy2=j;
            }
        }
        for(long long j=0;j<t1[i].size();j++)
        {
            if(t1[i][j]!=t2[i][j])
            {
                sy1=j;
                break;
            }
        }
        long long sum=0;
        for(long long j=0;j<t1[i].size();j++)
        {
            for(long long k=1;k<=n;k++)
            {
                if(j+s1[k].size()-1>t1[i].size()) continue;
                else
                {
                    long long uu=0;
                    for(long long l=0;l<s1[k].size();l++)
                    {
                        if(s1[k][l]==t1[i][l+j] && s2[k][l]==t2[i][l+j]) i=i;
                        else
                        {
                            uu=1;
                            break;
                        }
                    }
                    if(uu==0 && j<sy1 && j+s1[k].size()>sy2)
                    {
                        sum++;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
