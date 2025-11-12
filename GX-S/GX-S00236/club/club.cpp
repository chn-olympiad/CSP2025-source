#include<bits/stdc++.h>
using namespace std;
long long int a[111111],b[111111],c[111111];
int an=0,bn=0,cn=0;
int mnx(int sense)
{
    for(int i=1;i<=3;i++)
    {
        if(sense==a[i])
        {
            return 1;
        }
        else if(sense==b[i])
        {
           return 2;
        }
        else if(sense=c[i])
        {
            return 3;
        }
    }
    return 4;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int n;
    int mr;
    int p[4];
    int sum,sue;
    int zj;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        sum=0;
        cin>>n;
        zj=n;
        mr=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        an=mr;
        bn=mr;
        cn=mr;
        for(int i=1;i<=n;i++)
        {
                p[1]=a[i];
                p[2]=b[i];
                p[3]=c[i];
                sort(p+1,p+1+3);
                if(zj>0)
                {
                 if(mnx(p[3])==1&&an>0&&zj>0)
                 {
                        sum+=p[3];
                        an--;
                        zj--;
                 }
                 else if(mnx(p[3])==2&&bn>0&&zj>0)
                 {
                        sum+=p[3];
                        bn--;
                        zj--;
                 }
                 else if(mnx(p[3])==3&&cn>0&&zj>0)
                 {
                        sum+=p[3];
                        cn--;
                        zj--;
                 }
                }

        }
        cout<<sum<<endl;
     }
    return 0;
}
