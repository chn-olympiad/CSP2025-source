#include <bits/stdc++.h>
using namespace std;
long long t,n,suma,sumb,sumc;
struct st
{
    long long li[5];
}a[1000005],aa[1000005],bb[1000005],cc[1000005];
bool cmp(st x,st y)
{
    return x.li[1]-max(x.li[2],x.li[3])>y.li[1]-max(y.li[2],y.li[3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        long long ans=0;
        suma=sumb=sumc=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i].li[j];
            }
            if(a[i].li[1]>=a[i].li[2]&&a[i].li[1]>=a[i].li[3])
            {
                aa[++suma]=a[i];
            }
            else if(a[i].li[2]>=a[i].li[1]&&a[i].li[2]>=a[i].li[3])
            {
                bb[++sumb]=a[i];
            }
            else
            {
                cc[++sumc]=a[i];
            }
        }
        for(int i=1;i<=sumb;i++)
        {
            swap(bb[i].li[1],bb[i].li[2]);
        }
        for(int i=1;i<=sumc;i++)
        {
            swap(cc[i].li[1],cc[i].li[3]);
        }
        sort(aa+1,aa+suma+1,cmp);
        sort(bb+1,bb+sumb+1,cmp);
        sort(cc+1,cc+sumc+1,cmp);
        for(int i=1;i<=suma;i++)
        {
            if(i>n/2)
            {
                ans+=max(aa[i].li[2],aa[i].li[3]);
            }
            else
            {
                ans+=aa[i].li[1];
            }
        }
        for(int i=1;i<=sumb;i++)
        {
            if(i>n/2)
            {
                ans+=max(bb[i].li[2],bb[i].li[3]);
            }
            else
            {
                ans+=bb[i].li[1];
            }
        }
        for(int i=1;i<=sumc;i++)
        {            if(i>n/2)
            {
                ans+=max(cc[i].li[2],cc[i].li[3]);
            }
            else
            {
                ans+=cc[i].li[1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
