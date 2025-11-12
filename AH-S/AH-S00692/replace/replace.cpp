#include <bits/stdc++.h>
using namespace std;
string a1[200001];
string a2[200001];
string b1[200001];
string b2[200001];
long long main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q,sum=0;
    bool ans=true;
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>a1[i]>>a2[i];
    }
    for(long long i=1;i<=q;i++)
    {
        cin>>b1[i]>>b2[i];
    }
    for(long long z=1;z<=q;z++)
    {
        for(long long i=1;i<=4;i++)
        {
            for(long long j=1;j<=n-a1[z].length()+1;j++)
            {
                for(long long k=1;k<=a1[z].length();k++)
                {
                    if(a1[i][k]!=b1[j][j+k-1])
                    {
                        ans=false;
                        break;
                    }
                }
                if(ans)
                {
                    for(long long k=1;k<=a2[z].length();k++)
                    {
                        if(a2[i][k]!=b2[j][j+k-1])
                        {
                            ans=false;
                            break;
                        }
                    }
                    if(ans)
                    {
                        for(long long k=1;k<=a2[z].length();k++)
                        {
                            b2[j][j+k-1]=a2[i][k];
                        }
                    }
                }
            }
        }
        if(b1[z].length()==b2[z].length())
        {
            ans=true;
            for(long long i=1;i<=b1[z].length();i++)
            {
                if(b1[i]!=b2[i])
                {
                    ans=false;
                    break;
                }
            }
            if(ans)
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
