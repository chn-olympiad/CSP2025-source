#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int z;
    cin >>z;
    for(int i=0;i<=z-1;i++)
    {
        int n;
        cin >>n;
        int a[n],b[n],c[n];
        for(int i=0;i<=n-1;i++)
        {
            cin >>a[i];
            cin >>b[i];
            cin >>c[i];
            a[i]*=100;
            b[i]*=100;
            c[i]*=100;
            a[i]+=i;
            b[i]+=i;
            c[i]+=i;
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        int as=n-1,bs=n-1,cs=n-1;
        int pe[n]={};
        int f=0;
        int a1=0,b1=0,c1=0;
        for(int i=0;i<=(3*n)-1;i++)
        {
            if(pe[a[as]%100])
            {
                as--;
                continue;
            }
            if(pe[b[bs]%100])
            {
                bs--;
                continue;
            }
            if(pe[c[cs]%100])
            {
                cs--;
                continue;
            }
            if(a[as]>=b[bs]&&a[as]>=c[cs]&&a1<=n/2-1)
            {
                a1++;
                f+=a[as]/100;
                pe[a[as]%100]++;
            }
            else if(b[bs]>=a[as]&&b[bs]>=c[cs]&&b1<=n/2-1)
            {
                b1++;
                f+=b[bs]/100;
                pe[b[bs]%100]++;
            }
            else if(c1<=n/2-1)
            {
                c1++;
                f+=c[cs]/100;
                pe[c[cs]%100]++;
            }
        }
        cout <<f<<endl;
    }

    return 0;
}
