#include<iostream>
using namespace std;
int a[20005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1 || n==2)
    {
        cout<<0;
        return 0;
    }
    else if(n==3)
    {
        cout<<1;
    }
    else if(n==4)
    {
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=0;k<=1;k++)
                {
                    for(int p=0;p<=1;p++)
                    {
                        sum=0;int maxn=0;
                        if(i==1) {sum+=a[1]; maxn=max(maxn,a[1]);}
                        if(j==1) {sum+=a[2]; maxn=max(maxn,a[2]);}
                        if(k==1) {sum+=a[3]; maxn=max(maxn,a[3]);}
                        if(p==1) {sum+=a[4]; maxn=max(maxn,a[4]);}
                        if(sum> maxn*2) cnt++;
                    }
                }
            }
        }
        cout<<cnt;
    }
    else if(n==5)
    {
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=0;k<=1;k++)
                {
                    for(int p=0;p<=1;p++)
                    {
                        for(int z=0;z<=1;z++)
                        {
                            sum=0;int maxn=0;
                            if(i==1) {sum+=a[1]; maxn=max(maxn,a[1]);}
                            if(j==1) {sum+=a[2]; maxn=max(maxn,a[2]);}
                            if(k==1) {sum+=a[3]; maxn=max(maxn,a[3]);}
                            if(p==1) {sum+=a[4]; maxn=max(maxn,a[4]);}
                            if(z==1) {sum+=a[5]; maxn=max(maxn,a[5]);}
                            if(sum> maxn*2)
                            {
                                cnt++;

                            }
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
    else if(n==6)
    {
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=0;k<=1;k++)
                {
                    for(int p=0;p<=1;p++)
                    {
                        for(int z=0;z<=1;z++)
                        {
                            for(int d=0;d<=1;d++)
                            {
                                sum=0;int maxn=0;
                                if(i==1) {sum+=a[1]; maxn=max(maxn,a[1]);}
                                if(j==1) {sum+=a[2]; maxn=max(maxn,a[2]);}
                                if(k==1) {sum+=a[3]; maxn=max(maxn,a[3]);}
                                if(p==1) {sum+=a[4]; maxn=max(maxn,a[4]);}
                                if(z==1) {sum+=a[5]; maxn=max(maxn,a[5]);}
                                if(d==1) {sum+=a[6]; maxn=max(maxn,a[6]);}
                                if(sum> maxn*2)
                                {
                                    cnt++;

                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
    else if(n==7)
    {
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=0;k<=1;k++)
                {
                    for(int p=0;p<=1;p++)
                    {
                        for(int z=0;z<=1;z++)
                        {
                            for(int d=0;d<=1;d++)
                            {
                                for(int c=0;c<=1;c++)
                                {
                                    sum=0;int maxn=0;
                                    if(i==1) {sum+=a[1]; maxn=max(maxn,a[1]);}
                                    if(j==1) {sum+=a[2]; maxn=max(maxn,a[2]);}
                                    if(k==1) {sum+=a[3]; maxn=max(maxn,a[3]);}
                                    if(p==1) {sum+=a[4]; maxn=max(maxn,a[4]);}
                                    if(z==1) {sum+=a[5]; maxn=max(maxn,a[5]);}
                                    if(d==1) {sum+=a[6]; maxn=max(maxn,a[6]);}
                                    if(c==1) {sum+=a[7]; maxn=max(maxn,a[7]);}
                                    if(sum> maxn*2)
                                    {
                                        cnt++;

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
}
