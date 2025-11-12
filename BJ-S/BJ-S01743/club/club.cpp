#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int f[100010];
        int n,z1=0,z2=0,z3=0;
        cin>>n;
        int a[4][100005];
        for(int i=1;i<=n;i++)
        {
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[1][i]>a[2][i])
            {
                if(a[1][i]>a[3][i])
                {
                    f[i]=1;
                    z1++;
                }
                else
                {
                    f[i]=3;
                    z3++;
                }
            }
            else
            {
                if(a[2][i]>a[3][i])
                {
                    f[i]=2;
                    z2++;
                }
                else
                {
                    f[i]=3;
                    z3++;
                }
            }
        }
        if(z1<=n/2&&z2<=n/2&&z3<=n/2)
        {
            long long z=0;
            for(int i=1;i<=n;i++)
            {
                z+=a[f[i]][i];
            }
            cout<<z<<"\n";
        }
        else
        {
            while(z3>z2&&z3>z1&&z3>n/2)
            {
                int minn=1e9,x;
                for(int i=1;i<=n;i++)
                {
                    if(f[i]==3&&a[3][i]<minn)
                    {
                        minn=a[3][i];
                        x=i;
                    }
                }
                if(a[2][x]>a[1][x]&&z2+1<n/2)
                {
                    f[x]=2;
                    z3--;
                    z2++;
                }
                else
                {
                    f[x]=1;
                    z3--;
                    z2++;
                }
            }
            while(z2>z3&&z2>z1&&z2>n/2)
            {
                int minn=1e9,x;
                for(int i=1;i<=n;i++)
                {
                    if(f[i]==3&&a[2][i]<minn)
                    {
                        minn=a[2][i];
                        x=i;
                    }
                }
                if(a[3][x]>a[1][x]&&z3+1<n/2)
                {
                    f[x]=3;
                    z2--;
                    z3++;
                }
                else
                {
                    f[x]=1;
                    z2--;
                    z3++;
                }
            }
            while(z1>z2&&z1>z3&&z1>n/2)
            {
                int minn=1e9,x;
                for(int i=1;i<=n;i++)
                {
                    if(f[i]==1&&a[1][i]<minn)
                    {
                        minn=a[1][i];
                        x=i;
                    }
                }
                if(a[2][x]>a[3][x]&&z2+1<n/2)
                {
                    f[x]=2;
                    z1--;
                    z2++;
                }
                else
                {
                    f[x]=3;
                    z1--;
                    z2++;
                }
            }
            long long z=0;
            for(int i=1;i<=n;i++)
            {
                z+=a[f[i]][i];
            }
            cout<<z<<"\n";
        }
    }
    return 0;
}
