#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int b=a[n];
    if(n==1)
    {
        cout<<0;
    }
    else if(n==2)
    {
        if(a[1]+a[2]>b*2)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(n==3)
    {
        int ans=0;
        if(a[1]+a[2]>b*2)
        {
            ans++;
        }
        else
        {
            if(a[1]+a[3]>b*2)
            {
                ans++;
            }
            else
            {
                if(a[2]+a[3]>b*2)
                {
                    ans++;
                }
                else
                {
                    if(a[1]+a[2]+a[3]>b*2)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
    }
    else if(n==4)
    {
        int cnt=0;
        if(a[1]+a[2]>b*2)
        {
            cnt++;
        }
        else if(a[1]+a[3]>b*2)
        {
            cnt++;
        }
        else if(a[1]+a[4]>b*2)
        {
            cnt++;
        }
        else if(a[2]+a[3]>b*2)
        {
            cnt++;
        }
        else if(a[2]+a[4]>b*2)
        {
            cnt++;
        }
        else if(a[3]+a[4]>b*2)
        {
            cnt++;
        }
        else if(a[1]+a[2]+a[3]>b*2)
        {
            cnt++;
        }
        else if(a[1]+a[2]+a[4]>b*2)
        {
            cnt++;
        }
        else if(a[1]+a[3]+a[4]>b*2)
        {
            cnt++;
        }
        else if(a[2]+a[3]+a[4]>b*2)
        {
            cnt++;
        }
        else if(a[1]+a[2]+a[3]+a[4]>b*2)
        {
            cnt++;
        }
        cout<<cnt;
    }
    else if(n==5)
    {
        int q=0;
        if(a[1]+a[2]>b*2)
        {
            q++;
        }
        else if(a[1]+a[3]>b*2)
        {
            q++;
        }
        else if(a[1]+a[4]>b*2)
        {
            q++;
        }
        else if(a[1]+a[5]>b*2)
        {
            q++;
        }
        else if(a[2]+a[3]>b*2)
        {
            q++;
        }
        else if(a[2]+a[4]>b*2)
        {
            q++;
        }
        else if(a[2]+a[5]>b*2)
        {
            q++;
        }
        else if(a[3]+a[4]>b*2)
        {
            q++;
        }
        else if(a[3]+a[5]>b*2)
        {
            q++;
        }
        else if(a[4]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[3]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[4]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[3]+a[4]>b*2)
        {
            q++;
        }
        else if(a[1]+a[3]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[4]+a[5]>b*2)
        {
            q++;
        }
        else if(a[2]+a[3]+a[4]>b*2)
        {
            q++;
        }
        else if(a[2]+a[3]+a[5]>b*2)
        {
            q++;
        }
        else if(a[2]+a[5]+a[4]>b*2)
        {
            q++;
        }
        else if(a[3]+a[4]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[3]+a[4]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[3]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[4]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[3]+a[4]+a[5]>b*2)
        {
            q++;
        }
        else if(a[2]+a[3]+a[4]+a[5]>b*2)
        {
            q++;
        }
        else if(a[1]+a[2]+a[3]+a[4]+a[5]>b*2)
        {
            q++;
        }
        cout<<q;
    }
    return 0;
}
