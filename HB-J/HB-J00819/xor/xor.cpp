#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,k,z=1;
struct sss{
    int l;
    int r;
}b[5005];
bool pd(sss x,sss y)
{
    return x.r<y.r;

}
long long cf(int n)
{   int m=1;
    for(int i=1;i<=n;i++)
        m*=i;
    return m;
}
long long or1(long long m,long long b)
{   int x[21]={0},y[21]={0};
    long long aa=m,bb=b,h=0;
    if(aa%2==1)
        x[0]=1;
    else
        x[0]=0;
    if(bb%2==1)
        y[0]=1;
    else
        y[0]=0;
    if(bb==0)
        return aa;
    for(int i=20;i>=1;i--)
    {   long long m=cf(i);
        x[i]=aa/m;
        aa%=m;
        y[i]==bb/m;
        bb%=m;
    }

    for(int i=20;i>=0;i--)
    {   h*=2;
        if(x[i]!=y[i])
            h+=1;
    }
    return h;

}
void cz(int s)
{   int h=a[s];
    if(h==k)
    {   b[z].l=s;
        b[z].r=s;
        z++;
        return;
    }
    for(int i=s+1;i<=n;i++)
    {   h=or1(h,a[i]);
        if(h==k)
        {   b[z].l=s;
            b[z].r=i;
            z++;
            break;
        }
    }
}
int main()
{   freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long w=0,h=0;
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    for(long long i=1;i<=n;i++)
        cz(i);
    sort(b+1,b+z,pd);
    for(long long i=1;i<=z;i++)
        if(b[i].l>w)
        {
            w=b[i].r;
            h++;
        }
    cout<<h;
    return 0;
}
