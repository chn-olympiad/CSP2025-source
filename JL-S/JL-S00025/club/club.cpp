#include <bits/stdc++.h>
using namespace std;
long long n,m,h,h1,z,a[10],s[10],s1[100],s2[100],s3[100],b,c,d,a1,a2,a3,b1,b2,b3,k;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&m);
        b=m/2;
        for(int j=1;j<=m;j++)
        {
            z++;
            scanf("%lld%lld%lld",&a1,&a2,&a3);
            c=a1;
            s1[z]=a1;
            s2[z]=a2;
            s3[z]=a3;
            if(a2>a1&&a2>a3)
            {
                c=a2;
            }
            if(a3>a2&&a3>a1)
            {
                c=a3;
            }
            if(c==a1)
            {
                b1++;
            }
            if(c==a2)
            {
                b2++;
            }
            if(c==a3)
            {
                b3++;
            }
            a[j]=c;
            k=k+a[j];
        }
        if(b1<=b&&b2<=b&&b3<=b)
        {
             s[i]=k;
        }
        else
        {
            for(int x=1;x<=m;x++)
            {
                h=s1[x];
                if(s2[x]<h&&s2[x]>s3[x])
                {
                    h=s2[x];
                }
                if(s2[x]>h&&s2[x]<s3[x]&&s3[x]>h)
                {
                    h=s2[x];
                }
                if(s3[x]<h&&s3[x]>s2[x])
                {
                    h=s3[x];
                }
                h1=s1[x];
                if(s2[x]>h1&&s2[x]>s3[x])
                {
                    h1=s2[x];
                }
                if(s3[x]>h1&&s3[x]>s2[x])
                {
                    h1=s3[x];
                }

            }
            k=k-h1+h;
            s[i]=k;

        }
        b1=0;
        b2=0;
        b3=0;
        k=0;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld\n",s[i]);
    }
    return 0;
}
