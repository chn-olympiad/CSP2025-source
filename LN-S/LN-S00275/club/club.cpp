#include <bits/stdc++.h>
using namespace std;
struct people
{
    int m1;
    int m2;
    int m3;
};
people a[100005];
bool cmp(int c,int b)
{
    return c>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int nm;
    cin>>nm;
    for(int im=1;im<=nm;im++)
    {
        int n;
        cin>>n;
        int cluba[100],clubb[100],clubc[100];
        int ka=0,kb=0,kc=0;
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].m1>>a[i].m2>>a[i].m3;
            if(a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3)
            {
                ka++;
                cluba[ka]=i;
                sum+=a[i].m1;
            }
            else if(a[i].m2>=a[i].m1&&a[i].m2>=a[i].m3)
            {
                kb++;
                clubb[kb]=i;
                sum+=a[i].m2;
            }
            else
            {
                kc++;
                clubc[kc]=i;
                sum+=a[i].m3;
            }
        }
        int pd=n/2;
        if(pd>=ka&&pd>=kb&&pd>=kc)
        {
            cout<<sum;
            continue;
        }
        if(ka>n/2)
        {
            int s[100005];
            for(int j=1;j<=ka;j++)
            {
                s[j]=a[cluba[j]].m1-max(a[cluba[j]].m2,a[cluba[j]].m3);
            }
            sort(s+1,s+ka+1,cmp);
            while(ka>n/2)
            {
                sum-=s[ka];
                ka--;
            }
        }
        else if(kb>n/2)
        {
            int s[100005];
            for(int j=1;j<=kb;j++)
            {
                s[j]=a[clubb[j]].m2-max(a[clubb[j]].m1,a[clubb[j]].m3);
            }
            sort(s+1,s+kb+1,cmp);
            while(kb>n/2)
            {
                sum-=s[kb];
                kb--;
            }
        }
        else
        {
            int s[100005];
            for(int j=1;j<=kc;j++)
            {
                s[j]=a[clubc[j]].m3-max(a[clubc[j]].m1,a[clubc[j]].m2);
            }
            sort(s+1,s+kc+1,cmp);
            while(kc>n/2)
            {
                sum-=s[kc];
                kc--;
            }
        }
        cout<<sum<<endl;
    }
}
