#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,sum;
    cin>>n;
    long long s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int v,f;
    f=0;
    for(int a=0;a<n;a++)
    {
        for(int b=2;b<n;b++)
        {
            for(int c=0;c<n;c++)
            {
                v+=s[c];
                if(s[c]>f)
                {
                    f=s[c];
                }
            }
            if(2*f<v)
            {
                sum++;
            }
        }
    }
    cout<<sum%998244353<<endl;
    return 0;
}
