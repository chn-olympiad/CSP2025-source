#include<bits/stdc++.h>
using namespace std;
long long t;
bool cmp(int a,int b)
{
    return a>=b;
}
long long cf(long long a,long long b)
{
    for(int i=1;i<=b;i++)
    {
        a=a*a;
    }

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        long long n,m=0,rs[4];
        memset(rs,0,sizeof(rs));
        long long a[10001],b[10001],c[10001],t1[10001],t2[10001],t3[10001];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            t1[i]=0;
            t2[i]=0;
            t3[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=b[i]&&a[i]>=c[i]&&t1[i]==0&&rs[1]<n/2)
            {
                t1[i]++;
                rs[1]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]>=a[i]&&b[i]>=c[i]&&t2[i]==0&&rs[2]<n/2)
            {
                t2[i]++;
                rs[2]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i]>=b[i]&&c[i]>=a[i]&&t3[i]==0&&rs[3]<n/2)
            {
                t3[i]++;
                rs[3]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(t1[i]!=0)
            {
                m+=a[i];
            }
            else if(t2[i]!=0)
            {
                m+=b[i];
            }
            else if(t3[i]!=0)
            {
                m+=c[i];
            }
        }
        cout<<m<<endl;
    }

    return 0;
}
