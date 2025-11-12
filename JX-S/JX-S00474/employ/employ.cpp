#include <iostream>
#include <cstdio>
using namespace std;
long long n,p,m,c[2000005],x,o;
string s;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(o<m)
        {
            if(x<c[i])
            {
                if(s[i]!=0)
                {
                    o++;
                }
                else x++;
            }
        }
        if(o>=m)
        {
            p++;

        }
    }
    cout<<p%998244353;
    return 0;

}
