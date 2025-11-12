#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int MAXN=5100;
int n;
int a[MAXN];
bool vis[MAXN];
int ret;
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n==3)
    {
        if(a[1]+a[2]>a[3]) ret+=1;
    }
    else if(n==4)
    {
        if(a[1]+a[2]+a[3]>a[4]) ret+=1;
        for(int i=1;i<=2;i++)
        {
            for(int j=i+1;j<=3;j++)
            {
                for(int k=j+1;k<=4;k++)
                {
                    if(a[i]+a[j]>a[k]) ret+=1;
                }
            }
        }
    }
    else if(n==5)
    {
        if(a[1]+a[2]+a[3]+a[4]>a[5]) ret+=1;
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    if(a[i]+a[j]>a[k]) ret+=1;
                }
            }
        }
        for(int i=1;i<=2;i++)
        {
            for(int j=i+1;j<=3;j++)
            {
                for(int k=j+1;k<=4;k++)
                {
                    for(int p=k+1;p<=5;p++)
                    {
                        if(a[i]+a[j]+a[k]>a[p]) ret+=1;
                    }
                }
            }
        }
    }
    else if(n==6)
    {
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]) ret+=1;
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    if(a[i]+a[j]>a[k]) ret+=1;
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int p=k+1;p<=6;p++)
                    {
                        if(a[i]+a[j]+a[k]>a[p]) ret+=1;
                    }
                }
            }
        }
        for(int i=1;i<=2;i++)
        {
            for(int j=i+1;j<=3;j++)
            {
                for(int k=j+1;k<=4;k++)
                {
                    for(int p=k+1;p<=5;p++)
                    {
                        for(int q=p+1;q<=6;q++)
                        {
                            if(a[i]+a[j]+a[k]+a[p]>a[q]) ret+=1;
                        }
                    }
                }
            }
        }
    }
    cout<<ret;
    return 0;
}
