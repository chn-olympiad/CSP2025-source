#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool flag=1;
unsigned long long cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) flag=0;
    }
    if(flag==1)
    {
        cout<<n-2;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if((a[i]+a[j]+a[k])>a[k]*2)
                {
                    cnt++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int l=k+1;l<=n;l++)
                {
                    if((a[i]+a[j]+a[k]+a[l])>a[l]*2)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int l=k+1;l<=n;l++)
                {
                    for(int m=l+1;m<=n;m++)
                    {
                        if((a[i]+a[j]+a[k]+a[l]+a[m])>a[m]*2)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
