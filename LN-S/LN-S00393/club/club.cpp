#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n,a[10001],b[10001],c[10001];
int s,x,y,z,d,r[4],l[10001],v[4],k[10001];
int aa[10001],bb[10001],cc[10001];
int aaa,bbb,ccc;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int q=0;q<t;q++)
    {
        a[10001]={0};
        b[10001]={0};
        c[10001]={0};
        v[4]={0};
        s=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            aa[i]=a[i];
            bb[i]=b[i];
            cc[i]=c[i];
        }
        sort(aa,aa+n,cmp);
        sort(bb,bb+n,cmp);
        sort(cc,cc+n,cmp);
        for(int i=(n/2-1);i<n;i++)
        {
            aa[i]=0;
            bb[i]=0;
            cc[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            aaa=0;
            bbb=0;
            ccc=0;
            for(int j=0;j<n;j++)
            {
                if(a[i]==aa[j])
                {
                    aaa=1;
                }
                if(b[i]==bb[j])
                {
                    bbb=1;
                }
                if(c[i]==cc[j])
                {
                    ccc=1;
                }
            }
            if(aaa=0)
            {
                a[i]=0;
            }
            if(bbb=0)
            {
                b[i]=0;
            }
            if(ccc=0)
            {
                c[i]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            r[0]=a[i];
            r[1]=b[i];
            r[2]=c[i];
            sort(r,r+3,cmp);
            if(r[0]==a[i])
            {
                l[i]=1;
                k[i]=a[i];
            }
            if(r[0]==b[i])
            {
                l[i]=2;
                k[i]=b[i];
            }
            else
            {
                l[i]=3;
                k[i]=c[i];
            }
            s+=r[0];
         }
         cout<<s<<" ";
    }
    return 0;
}
