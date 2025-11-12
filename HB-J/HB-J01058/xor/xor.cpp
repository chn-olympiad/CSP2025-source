#include<bits/stdc++.h>
using namespace std;
const int mx=5*1E5+10;
int b[mx][30],c[30];
int a[mx],len[mx];
int kk,ans,n,k,xl,yl;
void mod2(int pp,int s)
{
    int i=1;
    while(s>0)
    {
        b[pp][i]=s%2;
        s/=2;
        i++;
    }
    len[pp]=i;
}
void x(int l,int r)
{
    kk=0;
    if(l==r)
    {
        kk=a[l];
        if(kk==k)ans++;
        xl=l,yl=r;
//      cout<<l<<" "<<r<<" "<<kk<<endl;
    }
    else
    {
        int maxn=0;
        int i,imaxn=0;
        for(i=l;i<=r;i++)
        {
            if(a[i]>maxn)imaxn=i;
            maxn=max(maxn,a[i]);
        }
        mod2(imaxn,a[imaxn]);
        int lmax=len[imaxn]-1;
//      cout<<l<<" "<<r<<" "<<kk<<endl;
        for(int i=1;i<=lmax;i++)
        {
            int f=1;
            for(int j=l;j<=r;j++)
            {
                if(len[j]<i)continue;
                if(b[j][i]==0)f=0;
            }
            c[i]=f;
        }
        int jia=0;
        for(int i=0;i<=lmax;i++)
        {
            if(c[i]==1)
            {
                jia=1;
                for(int j=1;j<=i;j++)
                {
                    jia*=2;
                }
                kk+=jia;
            }
        }
        xl=l,yl=r;
        if(kk==k)ans++;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int j;
    for(int i=1;i<=n;)
    {
        for(j=i;j<=n;j++)
        {
            int cnt=ans;
            x(i,j);
            if(ans-cnt==1)
            {
                i++;
              xl=max(xl,i);
              yl=max(yl,j);
            }
        }
        if(ans>=0)i=xl;
        i++;
    }
    cout<<ans;
    return 0;
}
