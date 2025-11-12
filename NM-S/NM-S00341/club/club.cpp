#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a1,a2,a3;
}a[100100];
long long t,n,ju3=0,ju2=0;
long long c[100100],c2[100100],sum=0,dp[100100]={};
bool cmp(node x,node y)
{
    return max(x.a1,x.a2)>max(y.a1,y.a2);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        ju3=0;
        ju2=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].a1);
            scanf("%d",&a[i].a2);
            scanf("%d",&a[i].a3);
            if(a[i].a2!=0)
            {
                ju2=1;
            }
            if(a[i].a3!=0)
            {
                ju3=1;
            }
            dp[i]=0;
        }
        if(ju2==0&&ju3==0)
        {
            for(int i=1;i<=n;i++)
            {
                c[i]=a[i].a1;
            }
            sort(c+1,c+1+n);
            for(int i=n;i>n/2;i--)
            {
                sum+=c[i];
            }
            cout<<sum<<endl;
            continue;
        }
        else if(ju3==0)
        {
            int k1=0,k2=0,jua=0,jub=0;
            for(int i=1;i<=n;i++)
            {
                if(k1>=n/2)
                {
                    jua=1;
                }
                if(k2>=n/2)
                {
                    jub=1;
                }
                if(a[i].a1>=a[i].a2&&jua==0)
                {
                    k1++;
                    dp[i]=max(dp[i],a[i].a1);
                }
                if(a[i].a1<a[i].a2&&jub==0)
                {
                    k2++;
                    dp[i]=max(dp[i],a[i].a2);
                }
            }
            for(int i=1;i<=n;i++)
            {
                sum+=dp[i];
            }
            cout<<sum<<endl;
            continue;
        }
    }
    return 0;
}
