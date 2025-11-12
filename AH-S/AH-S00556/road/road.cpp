#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[100005].c[100005];
int a_p[100005],b_p[100005],c_p[100005];
int tot1,tot2,tot3;
bool cmp1(long long x,long long y)
{
    return  (b[x]-a[x]>b[y]-a[y])&&;
}
bool cmp2(long long x,long long y)
{
    return  b[x]>b[y];
}
bool cmp3(long long x,long long y)
{
    return  c[x]>c[y];
}
int main()
{
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);

    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            if(a[i]>b[i]&&a[i]>c[i])
                a_p[++tot1]=i;
            else if(b[i]>a]i&&b[i]>c[i])
                b_p[++tot2]=i;
            else
                c_p[++tot3]=i;
        }
        if(tot1>n/2)
        {
            sort(a_p+1,a_p+tot1+1,cmp1);
            for(int i=n/2+1;i<=tot1;++i)
            {
                if(b[a_p[i]>c[a_p[i])
                {
                    b_p[++tot2]=a_p[i];
                }
                else
                {
                    c_p[++tot3]=a_p[i];
                }

            }
            cnt=n/2;
        }
         if(tot2>n/2)
        {
            sort(b_p+1,b_p+tot2+1,cmp1);
            for(int i=n/2+1;i<=tot2;++i)
            {
                if(a[b_p[i]>c[b_p[i])
                {
                    a_p[++tot1]=b_p[i];
                }
                else
                {
                    c_p[++tot3]=b_p[i];
                }

            }
            cnt=n/2;
        }
         if(tot3>n/2)
         {

         }
         for(int i=1;i<=tot1;++i)
            ans+=a[a_p[i]];
         for(int i=1;i<=tot2;++i)
            ans+=b[b_p[i]];
            for(int i=1;i<=tot3;++i)
            ans+=c[c_p[i]];
    }
    return 0;
}
