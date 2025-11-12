#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010],ans;
int drr(int ma,int sm,int u)
{
    for (int z=u+1;z<=n;z++)
    {
        if(a[z]>ma)
            ma=a[z];
        int smm=sm+a[z];
        if(smm>ma*2)
        {
            ans++;
            if(n-z>1)
            {
                drr(ma,smm,z);
            }
        }
        else{
            if(n-z>1)
            {
                drr(ma,smm,z);
            }
        }
    }
}
int drp()
{
    for (int i=1;i<=n-2;i++)
    {
        int mx=a[i];
        for (int j=i+1;j<=n-1;j++)
        {
            if(a[j]>mx)
                mx=a[j];
            for (int k=j+1;k<=n;k++)
            {
                if(a[k]>mx)
                    mx=a[k];
                int q=s[j-1]-s[i];
                int p=s[k-1]-s[j];
                int sum=s[k]-q-p-s[i]+a[i];
                if(sum>mx*2){
                    ans++;
                    if(n>3&&n-k>1)
                    {
                        drr(mx,sum,k);
                    }
                }
                else{
                    if(n>3&&n-k>1)
                    {
                        drr(mx,sum,k);
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    drp();
    ans=ans%998244353;
    cout<<ans;
    return 0;
}
