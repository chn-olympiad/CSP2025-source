#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,w,s=0;
    cin>>n>>w;
    long long a[n];
    bool b[n]={0};
    for(long long i=0;i<n;i++){cin>>a[i];if(a[i]==w){s++;b[i]=true;}}
    for(long long i=2;i<=n;i++)
    {
        for(long long j=0;j+i<=n;j++)
        {
            bool z=0;
            long long h=0;
            for(long long k=j;k<j+i;k++)
            {
                if(b[k]){z=1;break;}
                h^=a[k];
            }
            if(z)continue;
            if(h==w)
            {
                s++;
                for(long long k=j;k<j+i;k++)b[k]=1;
                j++;
            }
        }
    }
    cout<<s;
    return 0;
}
