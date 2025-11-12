#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct node
{
    int z;
    int x;
};
int t,n,a[N][5],c[5];
int mian()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>n;
        node b[N];
        int l[N],v[4],h;
        for(int j=1;j<=n;j++)
        {
            int r[3];

            for(int k=1;k<=3;k++)
            {

                if(a[j][k]>a[j][k-1])
                {
                    l[j]=a[j][k]-b[j].x;
                    b[j].z=k;
                    b[j].x=a[j][k];
                    h++;
                }
            }
            v[h]++;
            c[t]+=b[j].x;

        }
        sort (l+1,l+1+n);
        if(v[h]>n/2)
        {
            for(int j=1;j<=n/2-v[h];j++)
            {
                c[t]-=l[j];

            }

        }
    }
    for(int i=1;i<=t;i++)
    {
        cout <<c[t];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
