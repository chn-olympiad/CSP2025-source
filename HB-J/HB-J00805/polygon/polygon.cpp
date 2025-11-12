#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long s[5005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
            flag=0;
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(n==3)
    {
        if(a[2]+a[1]+a[3]>a[1]*2)
        {
            cout<<1;
            return 0;
        }
        cout<<"0";
        return 0;
    }
    if(n==4)
    {
        int cnt=0;
        if(a[1]+a[2]+a[3]>a[1]*2)
            cnt++;
        if(a[1]+a[2]+a[4]>a[1]*2)
            cnt++;
        if(a[2]+a[3]+a[4]>a[2]*2)
            cnt++;
        if(a[1]+a[2]+a[3]+a[4]>a[1]*2)
            cnt++;
        cout<<cnt;
        return 0;
    }
    if(n==5)
    {
        int cnt=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(a[i]+a[j]+a[k]>a[i]*2)
                        cnt++;
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]>a[1]*2)
            cnt++;
        if(a[1]+a[2]+a[3]+a[5]>a[1]*2)
            cnt++;
        if(a[2]+a[3]+a[4]+a[5]>a[2]*2)
            cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[1]*2)
            cnt++;
        cout<<cnt;
        return 0;
    }
    if(n==6)
    {
        int cnt=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(a[i]+a[j]+a[k]>a[i]*2)
                        cnt++;
                }
            }
        }
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    for(int h=k+1;h<=n;h++)
                    {
                        if(a[i]+a[j]+a[k]+a[h]>a[i]*2)
                            cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                for(int k=j+1;k<=n-2;k++)
                {
                    for(int h=k+1;h<=n-1;h++)
                    {
                        for(int f=h+1;f<=n;f++)
                        {
                            if(a[i]+a[j]+a[k]+a[h]+a[f]>a[i]*2)
                            cnt++;
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[1]*2)
            cnt++;
        cout<<cnt;
        return 0;
    }
    if(n==7)
    {
        int cnt=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(a[i]+a[j]+a[k]>a[i]*2)
                        cnt++;
                }
            }
        }
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    for(int h=k+1;h<=n;h++)
                    {
                        if(a[i]+a[j]+a[k]+a[h]>a[i]*2)
                            cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                for(int k=j+1;k<=n-2;k++)
                {
                    for(int h=k+1;h<=n-1;h++)
                    {
                        for(int f=h+1;f<=n;f++)
                        {
                            if(a[i]+a[j]+a[k]+a[h]+a[f]>a[i]*2)
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-5;i++)
        {
            for(int j=i+1;j<=n-4;j++)
            {
                for(int k=j+1;k<=n-3;k++)
                {
                    for(int h=k+1;h<=n-2;h++)
                    {
                        for(int f=h+1;f<=n-1;f++)
                        {
                            for(int s=f+1;s<=n;s++)
                            {
                                if(a[i]+a[j]+a[k]+a[h]+a[f]+a[s]>a[i]*2)
                                    cnt++;
                            }

                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[1]*2)
            cnt++;
        cout<<cnt;
        return 0;
    }
    if(n==8)
    {
        int cnt=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(a[i]+a[j]+a[k]>a[i]*2)
                        cnt++;
                }
            }
        }
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    for(int h=k+1;h<=n;h++)
                    {
                        if(a[i]+a[j]+a[k]+a[h]>a[i]*2)
                            cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                for(int k=j+1;k<=n-2;k++)
                {
                    for(int h=k+1;h<=n-1;h++)
                    {
                        for(int f=h+1;f<=n;f++)
                        {
                            if(a[i]+a[j]+a[k]+a[h]+a[f]>a[i]*2)
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-5;i++)
        {
            for(int j=i+1;j<=n-4;j++)
            {
                for(int k=j+1;k<=n-3;k++)
                {
                    for(int h=k+1;h<=n-2;h++)
                    {
                        for(int f=h+1;f<=n-1;f++)
                        {
                            for(int s=f+1;s<=n;s++)
                            {
                                if(a[i]+a[j]+a[k]+a[h]+a[f]+a[s]>a[i]*2)
                                    cnt++;
                            }

                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-6;i++)
        {
            for(int j=i+1;j<=n-5;j++)
            {
                for(int k=j+1;k<=n-4;k++)
                {
                    for(int h=k+1;h<=n-3;h++)
                    {
                        for(int f=h+1;f<=n-2;f++)
                        {
                            for(int s=f+1;s<=n-1;s++)
                            {
                                for(int d=s+1;d<=n;d++)
                                {
                                    if(a[i]+a[j]+a[k]+a[h]+a[f]+a[s]+a[d]>a[i]*2)
                                        cnt++;
                                }
                            }
                         }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[1]*2)
                cnt++;
        cout<<cnt;
        return 0;
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            if(s[j]-s[i]>s[i]*2)
            {
                sum+=(n-j+1);
                sum=sum%998244353;
            }
        }
    }
    cout<<sum;
    return 0;
}
