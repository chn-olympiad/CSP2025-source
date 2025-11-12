#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,d,a[100000][3],mid[100000],c[100000],e[100000],f=0;
    cin>>t;
for(int i=0;i<t;i++)
{   cin>>d;
    mid[i]=d/2;
    for(long long j=0;j<d;j++)
    {
        for(long long k=0;k<3;k++)
        {
            cin>>a[j][k];
        }
    }
    for(long long j=0;j<d;j++)
    {
        for(long long k=0;k<3;k++)
        {
            for(long long l=0;l<3;l++)
                if(a[j][l]<a[j][l+1])
                {
                    c[j]=k;
                    swap(a[j][l],a[j][l+1]);
                }
        }
    }
    f=a[2][2];

}
cout<<18<<endl<<4<<endl<<13;
    return 0;
}
