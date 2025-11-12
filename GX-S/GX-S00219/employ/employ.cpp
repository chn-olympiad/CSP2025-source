#include<bits/stdc++.h>
using namespace std;
long long n,m,nd[509],nx[509];
int  gjr(int a,int b)
{
    int k=0;
    for(int i=1;i<=a;i++)
    {
        int l=0,o=0;
        for(int j=1;j<=a;j++)
        {
            if(o>nx[i]||nd[j]==0)
            {
                o++;
            }
            else if(nd[j]==1)
            {
                l++;
            }
        }
        if(l>=b)
        {
            k++;
        }
    }
    return k;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>nd[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>nx[i];
    }
    cout<<(gjr(n,m)%998);
    return 0;
}
