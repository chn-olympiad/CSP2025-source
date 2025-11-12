#include<bits/stdc++.h>
using namespace std;
bool f[505],k;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%b",&f[i]);
        if(f[i]==0)
        {
            k=true;
        }
    }
    if(m==n&&k)
    {
        cout<<0;
    }
    else if(m==n&&!k)
    {
        cout<<n*n(n-1)/2;
    }
    return 0;
}
