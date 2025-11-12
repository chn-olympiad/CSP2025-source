#include <bits/stdc++.h>
using namespace std;
int a[1005];
const int mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))cout<<1;
    }
    if(n==4)
    {
        int cnt=0;
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))cnt++;
        if(a[1]+a[2]+a[4]>2*max(max(a[1],a[2]),a[4]))cnt++;
        if(a[1]+a[3]+a[4]>2*max(max(a[1],a[4]),a[3]))cnt++;
        if(a[4]+a[2]+a[3]>2*max(max(a[4],a[2]),a[3]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]>2*max(max(max(a[1],a[2]),a[3]),a[4]))cnt++;
        cout<<cnt;
    }
    if(n==5)
    {
        int cnt=0;
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    if(i==j||j==k||i==k)continue;
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
                    {
                        cnt++;
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]>2*max(max(max(a[1],a[2]),a[3]),a[4]))cnt++;
        if(a[1]+a[2]+a[3]+a[5]>2*max(max(max(a[1],a[2]),a[3]),a[5]))cnt++;
        if(a[1]+a[2]+a[5]+a[4]>2*max(max(max(a[1],a[2]),a[5]),a[4]))cnt++;
        if(a[1]+a[5]+a[3]+a[4]>2*max(max(max(a[1],a[5]),a[3]),a[4]))cnt++;
        if(a[5]+a[2]+a[3]+a[4]>2*max(max(max(a[5],a[2]),a[3]),a[4]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]))cnt++;
        cout<<cnt;
    }
    if(n==6)
    {
        int cnt=0;
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    if(i==j||j==k||i==k)continue;
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[6]>2*max(max(max(max(a[1],a[2]),a[3]),a[4]),a[6]))cnt++;
        if(a[1]+a[2]+a[3]+a[6]+a[5]>2*max(max(max(max(a[1],a[2]),a[3]),a[6]),a[5]))cnt++;
        if(a[1]+a[2]+a[6]+a[4]+a[5]>2*max(max(max(max(a[1],a[2]),a[6]),a[4]),a[5]))cnt++;
        if(a[1]+a[6]+a[3]+a[4]+a[5]>2*max(max(max(max(a[1],a[6]),a[3]),a[4]),a[5]))cnt++;
        if(a[6]+a[2]+a[3]+a[4]+a[5]>2*max(max(max(max(a[6],a[2]),a[3]),a[4]),a[5]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]))cnt++;
        cout<<cnt;
    }
    if(n==7)
    {
        int cnt=0;
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[7]>2*max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[7]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[7]+a[6]>2*max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[7]),a[6]))cnt++;
        if(a[1]+a[2]+a[3]+a[7]+a[5]+a[6]>2*max(max(max(max(max(a[1],a[2]),a[3]),a[7]),a[5]),a[6]))cnt++;
        if(a[1]+a[2]+a[7]+a[4]+a[5]+a[6]>2*max(max(max(max(max(a[1],a[2]),a[7]),a[4]),a[5]),a[6]))cnt++;
        if(a[1]+a[7]+a[3]+a[4]+a[5]+a[6]>2*max(max(max(max(max(a[1],a[7]),a[3]),a[4]),a[5]),a[6]))cnt++;
        if(a[7]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(max(max(max(a[7],a[2]),a[3]),a[4]),a[5]),a[6]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]))cnt++;
        cout<<cnt;
    }
    if(n==8)
    {
        int cnt=0;
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[8]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[8]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[8]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[8]),a[7]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[8]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[8]),a[6]),a[7]))cnt++;
        if(a[1]+a[2]+a[3]+a[8]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[8]),a[5]),a[6]),a[7]))cnt++;
        if(a[1]+a[2]+a[8]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[8]),a[4]),a[5]),a[6]),a[7]))cnt++;
        if(a[1]+a[8]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[8]),a[3]),a[4]),a[5]),a[6]),a[7]))cnt++;
        if(a[8]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[8],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]))cnt++;
        cout<<cnt;
    }
    if(n==9)
    {
        int cnt=0;
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[9]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[9]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[9]),a[8]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[9]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[9]),a[7]),a[8]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[9]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[9]),a[6]),a[7]),a[8]))cnt++;
        if(a[1]+a[2]+a[3]+a[9]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[9]),a[5]),a[6]),a[7]),a[8]))cnt++;
        if(a[1]+a[2]+a[9]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[9]),a[4]),a[5]),a[6]),a[7]),a[8]))cnt++;
        if(a[1]+a[9]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[9]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]))cnt++;
        if(a[9]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[9],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==10)
    {
        int cnt=0;
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[10]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[10]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[10]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[10]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[10]),a[8]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[10]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[10]),a[7]),a[8]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[10]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[10]),a[6]),a[7]),a[8]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[10]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[10]),a[5]),a[6]),a[7]),a[8]),a[9]))cnt++;
        if(a[1]+a[2]+a[10]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[10]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]))cnt++;
        if(a[1]+a[10]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[10]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]))cnt++;
        if(a[10]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[10],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==11)
    {
        int cnt=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=i+1;j<=10;j++)
            {
                for(int k=j+1;k<=11;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    for(int l=k+1;l<=11;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        for(int m=l+1;m<=11;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            for(int o=m+1;o<=11;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                for(int p=o+1;p<=11;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                    for(int q=p+1;q<=11;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        for(int r=q+1;r<=11;r++)
                                        {
                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r)continue;
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]))cnt++;
                                            cnt%=mod;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[11]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[11]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[11]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[11]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[11]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[11]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[11]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[11]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[11]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[11]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[11]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[11]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[11]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[11]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[11]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[11]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[11]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[11]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[11],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==12)
    {
        int cnt=0;
        for(int i=1;i<=10;i++)
        {
            for(int j=i+1;j<=11;j++)
            {
                for(int k=j+1;k<=12;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=i+1;j<=10;j++)
            {
                for(int k=j+1;k<=11;k++)
                {
                    for(int l=k+1;l<=12;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    for(int l=k+1;l<=11;l++)
                    {
                        for(int m=l+1;m<=12;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        for(int m=l+1;m<=11;m++)
                        {
                            for(int o=m+1;o<=12;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            for(int o=m+1;o<=11;o++)
                            {
                                for(int p=o+1;p<=12;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                for(int p=o+1;p<=11;p++)
                                {
                                    for(int q=p+1;q<=12;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                    for(int q=p+1;q<=11;q++)
                                    {
                                        for(int r=q+1;r<=12;r++)
                                        {
                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r)continue;
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]))cnt++;
                                            cnt%=mod;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        for(int r=q+1;r<=11;r++)
                                        {
                                            for(int s=r+1;s<=12;s++)
                                            {
                                                if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s)continue;
                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]>2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]))cnt++;
                                                cnt%=mod;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[12]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[12]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[12]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[12]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[12]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[12]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[12]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[12]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[12]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[12]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[12]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[12]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[12]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[12]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[12]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[12]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[12]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[12]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[1],a[12]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[12]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>2*max(max(max(max(max(max(max(max(max(max(a[12],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==13)
    {
        int cnt=0;
        for(int i=1;i<=11;i++)
        {
            for(int j=i+1;j<=12;j++)
            {
                for(int k=j+1;k<=13;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=10;i++)
        {
            for(int j=i+1;j<=11;j++)
            {
                for(int k=j+1;k<=12;k++)
                {
                    for(int l=k+1;l<=13;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=i+1;j<=10;j++)
            {
                for(int k=j+1;k<=11;k++)
                {
                    for(int l=k+1;l<=12;l++)
                    {
                        for(int m=l+1;m<=13;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    for(int l=k+1;l<=11;l++)
                    {
                        for(int m=l+1;m<=12;m++)
                        {
                            for(int o=m+1;o<=13;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        for(int m=l+1;m<=11;m++)
                        {
                            for(int o=m+1;o<=12;o++)
                            {
                                for(int p=o+1;p<=13;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            for(int o=m+1;o<=11;o++)
                            {
                                for(int p=o+1;p<=12;p++)
                                {
                                    for(int q=p+1;q<=13;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                for(int p=o+1;p<=11;p++)
                                {
                                    for(int q=p+1;q<=12;q++)
                                    {
                                        for(int r=q+1;r<=13;r++)
                                        {
                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r)continue;
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]))cnt++;
                                            cnt%=mod;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                    for(int q=p+1;q<=11;q++)
                                    {
                                        for(int r=q+1;r<=12;r++)
                                        {
                                            for(int s=r+1;s<=13;s++)
                                            {
                                                if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s)continue;
                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]>2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]))cnt++;
                                                cnt%=mod;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        for(int r=q+1;r<=11;r++)
                                        {
                                            for(int s=r+1;s<=12;s++)
                                            {
                                                for(int t=s+1;t<=13;t++)
                                                {
                                                    if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t)continue;
                                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]>2*max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]))cnt++;
                                                    cnt%=mod;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[13]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[13]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[13]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[13]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[13]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[13]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[13]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[13]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[13]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[13]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[13]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[13]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[13]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[13]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[13]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[13]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[13]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[13]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[13]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[1],a[13]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[13]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>2*max(max(max(max(max(max(max(max(max(max(max(a[13],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==14)
    {
        int cnt=0;
        for(int i=1;i<=12;i++)
        {
            for(int j=i+1;j<=13;j++)
            {
                for(int k=j+1;k<=14;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=11;i++)
        {
            for(int j=i+1;j<=12;j++)
            {
                for(int k=j+1;k<=13;k++)
                {
                    for(int l=k+1;l<=14;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=10;i++)
        {
            for(int j=i+1;j<=11;j++)
            {
                for(int k=j+1;k<=12;k++)
                {
                    for(int l=k+1;l<=13;l++)
                    {
                        for(int m=l+1;m<=14;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=i+1;j<=10;j++)
            {
                for(int k=j+1;k<=11;k++)
                {
                    for(int l=k+1;l<=12;l++)
                    {
                        for(int m=l+1;m<=13;m++)
                        {
                            for(int o=m+1;o<=14;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    for(int l=k+1;l<=11;l++)
                    {
                        for(int m=l+1;m<=12;m++)
                        {
                            for(int o=m+1;o<=13;o++)
                            {
                                for(int p=o+1;p<=14;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        for(int m=l+1;m<=11;m++)
                        {
                            for(int o=m+1;o<=12;o++)
                            {
                                for(int p=o+1;p<=13;p++)
                                {
                                    for(int q=p+1;q<=14;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            for(int o=m+1;o<=11;o++)
                            {
                                for(int p=o+1;p<=12;p++)
                                {
                                    for(int q=p+1;q<=13;q++)
                                    {
                                        for(int r=q+1;r<=14;r++)
                                        {
                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r)continue;
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]))cnt++;
                                            cnt%=mod;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                for(int p=o+1;p<=11;p++)
                                {
                                    for(int q=p+1;q<=12;q++)
                                    {
                                        for(int r=q+1;r<=13;r++)
                                        {
                                            for(int s=r+1;s<=14;s++)
                                            {
                                                if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s)continue;
                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]>2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]))cnt++;
                                                cnt%=mod;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                    for(int q=p+1;q<=11;q++)
                                    {
                                        for(int r=q+1;r<=12;r++)
                                        {
                                            for(int s=r+1;s<=13;s++)
                                            {
                                                for(int t=s+1;t<=14;t++)
                                                {
                                                    if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t)continue;
                                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]>2*max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]))cnt++;
                                                    cnt%=mod;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        for(int r=q+1;r<=11;r++)
                                        {
                                            for(int s=r+1;s<=12;s++)
                                            {
                                                for(int t=s+1;t<=13;t++)
                                                {
                                                    for(int u=t+1;u<=14;u++)
                                                    {
                                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t||t==u)continue;
                                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]+a[u]>2*max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]),a[u]))cnt++;
                                                        cnt%=mod;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[14]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[14]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[14]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[14]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[14]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[14]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[14]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[14]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[14]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[14]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[14]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[14]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[14]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[14]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[14]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[14]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[14]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[14]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[14]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[14]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[14]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[14]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[14]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[14],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==15)
    {
        int cnt=0;
        for(int i=1;i<=13;i++)
        {
            for(int j=i+1;j<=14;j++)
            {
                for(int k=j+1;k<=15;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=12;i++)
        {
            for(int j=i+1;j<=13;j++)
            {
                for(int k=j+1;k<=14;k++)
                {
                    for(int l=k+1;l<=15;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=11;i++)
        {
            for(int j=i+1;j<=12;j++)
            {
                for(int k=j+1;k<=13;k++)
                {
                    for(int l=k+1;l<=14;l++)
                    {
                        for(int m=l+1;m<=15;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=10;i++)
        {
            for(int j=i+1;j<=11;j++)
            {
                for(int k=j+1;k<=12;k++)
                {
                    for(int l=k+1;l<=13;l++)
                    {
                        for(int m=l+1;m<=14;m++)
                        {
                            for(int o=m+1;o<=15;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=i+1;j<=10;j++)
            {
                for(int k=j+1;k<=11;k++)
                {
                    for(int l=k+1;l<=12;l++)
                    {
                        for(int m=l+1;m<=13;m++)
                        {
                            for(int o=m+1;o<=14;o++)
                            {
                                for(int p=o+1;p<=15;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    for(int l=k+1;l<=11;l++)
                    {
                        for(int m=l+1;m<=12;m++)
                        {
                            for(int o=m+1;o<=13;o++)
                            {
                                for(int p=o+1;p<=14;p++)
                                {
                                    for(int q=p+1;q<=15;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        for(int m=l+1;m<=11;m++)
                        {
                            for(int o=m+1;o<=12;o++)
                            {
                                for(int p=o+1;p<=13;p++)
                                {
                                    for(int q=p+1;q<=14;q++)
                                    {
                                        for(int r=q+1;r<=15;r++)
                                        {
                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r)continue;
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]))cnt++;
                                            cnt%=mod;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            for(int o=m+1;o<=11;o++)
                            {
                                for(int p=o+1;p<=12;p++)
                                {
                                    for(int q=p+1;q<=13;q++)
                                    {
                                        for(int r=q+1;r<=14;r++)
                                        {
                                            for(int s=r+1;s<=15;s++)
                                            {
                                                if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s)continue;
                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]>2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]))cnt++;
                                                cnt%=mod;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                for(int p=o+1;p<=11;p++)
                                {
                                    for(int q=p+1;q<=12;q++)
                                    {
                                        for(int r=q+1;r<=13;r++)
                                        {
                                            for(int s=r+1;s<=14;s++)
                                            {
                                                for(int t=s+1;t<=15;t++)
                                                {
                                                    if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t)continue;
                                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]>2*max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]))cnt++;
                                                    cnt%=mod;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                    for(int q=p+1;q<=11;q++)
                                    {
                                        for(int r=q+1;r<=12;r++)
                                        {
                                            for(int s=r+1;s<=13;s++)
                                            {
                                                for(int t=s+1;t<=14;t++)
                                                {
                                                    for(int u=t+1;u<=15;u++)
                                                    {
                                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t||t==u)continue;
                                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]+a[u]>2*max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]),a[u]))cnt++;
                                                        cnt%=mod;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        for(int r=q+1;r<=11;r++)
                                        {
                                            for(int s=r+1;s<=12;s++)
                                            {
                                                for(int t=s+1;t<=13;t++)
                                                {
                                                    for(int u=t+1;u<=14;u++)
                                                    {
                                                        for(int v=u+1;v<=15;v++)
                                                        {
                                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t||t==u||u==v)continue;
                                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]+a[u]+a[v]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]),a[u]),a[v]))cnt++;
                                                            cnt%=mod;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[15]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[15]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[15]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[15]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[15]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[15]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[15]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[15]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[15]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[15]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[15]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[15]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[15]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[15]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[15]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[15]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[15]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[15]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[15]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[15]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[15]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[15]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[15]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[15]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[15]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[15],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    if(n==16)
    {
        int cnt=0;
        for(int i=1;i<=14;i++)
        {
            for(int j=i+1;j<=15;j++)
            {
                for(int k=j+1;k<=16;k++)
                {
                    if(i==j||j==k)
                    {
                        continue;
                    }
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))cnt++;
                }
            }
        }
        for(int i=1;i<=13;i++)
        {
            for(int j=i+1;j<=14;j++)
            {
                for(int k=j+1;k<=15;k++)
                {
                    for(int l=k+1;l<=16;l++)
                    {
                        if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
                        if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=12;i++)
        {
            for(int j=i+1;j<=13;j++)
            {
                for(int k=j+1;k<=14;k++)
                {
                    for(int l=k+1;l<=15;l++)
                    {
                        for(int m=l+1;m<=16;m++)
                        {
                            if(i==j||j==k||k==l||l==m)continue;
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]))cnt++;
                            cnt%=mod;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=11;i++)
        {
            for(int j=i+1;j<=12;j++)
            {
                for(int k=j+1;k<=13;k++)
                {
                    for(int l=k+1;l<=14;l++)
                    {
                        for(int m=l+1;m<=15;m++)
                        {
                            for(int o=m+1;o<=16;o++)
                            {
                                if(i==j||j==k||k==l||l==m||m==o)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]))cnt++;
                                cnt%=mod;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=10;i++)
        {
            for(int j=i+1;j<=11;j++)
            {
                for(int k=j+1;k<=12;k++)
                {
                    for(int l=k+1;l<=13;l++)
                    {
                        for(int m=l+1;m<=14;m++)
                        {
                            for(int o=m+1;o<=15;o++)
                            {
                                for(int p=o+1;p<=16;p++)
                                {
                                if(i==j||j==k||k==l||l==m||m==o||o==p)continue;
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]))cnt++;
                                cnt%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=i+1;j<=10;j++)
            {
                for(int k=j+1;k<=11;k++)
                {
                    for(int l=k+1;l<=12;l++)
                    {
                        for(int m=l+1;m<=13;m++)
                        {
                            for(int o=m+1;o<=14;o++)
                            {
                                for(int p=o+1;p<=15;p++)
                                {
                                    for(int q=p+1;q<=16;q++)
                                    {
                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q)continue;
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]))cnt++;
                                        cnt%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                for(int k=j+1;k<=10;k++)
                {
                    for(int l=k+1;l<=11;l++)
                    {
                        for(int m=l+1;m<=12;m++)
                        {
                            for(int o=m+1;o<=13;o++)
                            {
                                for(int p=o+1;p<=14;p++)
                                {
                                    for(int q=p+1;q<=15;q++)
                                    {
                                        for(int r=q+1;r<=16;r++)
                                        {
                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r)continue;
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]))cnt++;
                                            cnt%=mod;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                for(int k=j+1;k<=9;k++)
                {
                    for(int l=k+1;l<=10;l++)
                    {
                        for(int m=l+1;m<=11;m++)
                        {
                            for(int o=m+1;o<=12;o++)
                            {
                                for(int p=o+1;p<=13;p++)
                                {
                                    for(int q=p+1;q<=14;q++)
                                    {
                                        for(int r=q+1;r<=15;r++)
                                        {
                                            for(int s=r+1;s<=16;s++)
                                            {
                                                if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s)continue;
                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]>2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]))cnt++;
                                                cnt%=mod;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
        {
            for(int j=i+1;j<=7;j++)
            {
                for(int k=j+1;k<=8;k++)
                {
                    for(int l=k+1;l<=9;l++)
                    {
                        for(int m=l+1;m<=10;m++)
                        {
                            for(int o=m+1;o<=11;o++)
                            {
                                for(int p=o+1;p<=12;p++)
                                {
                                    for(int q=p+1;q<=13;q++)
                                    {
                                        for(int r=q+1;r<=14;r++)
                                        {
                                            for(int s=r+1;s<=15;s++)
                                            {
                                                for(int t=s+1;t<=16;t++)
                                                {
                                                    if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t)continue;
                                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]>2*max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]))cnt++;
                                                    cnt%=mod;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=i+1;j<=6;j++)
            {
                for(int k=j+1;k<=7;k++)
                {
                    for(int l=k+1;l<=8;l++)
                    {
                        for(int m=l+1;m<=9;m++)
                        {
                            for(int o=m+1;o<=10;o++)
                            {
                                for(int p=o+1;p<=11;p++)
                                {
                                    for(int q=p+1;q<=12;q++)
                                    {
                                        for(int r=q+1;r<=13;r++)
                                        {
                                            for(int s=r+1;s<=14;s++)
                                            {
                                                for(int t=s+1;t<=15;t++)
                                                {
                                                    for(int u=t+1;u<=16;u++)
                                                    {
                                                        if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t||t==u)continue;
                                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]+a[u]>2*max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]),a[u]))cnt++;
                                                        cnt%=mod;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=i+1;j<=5;j++)
            {
                for(int k=j+1;k<=6;k++)
                {
                    for(int l=k+1;l<=7;l++)
                    {
                        for(int m=l+1;m<=8;m++)
                        {
                            for(int o=m+1;o<=9;o++)
                            {
                                for(int p=o+1;p<=10;p++)
                                {
                                    for(int q=p+1;q<=11;q++)
                                    {
                                        for(int r=q+1;r<=12;r++)
                                        {
                                            for(int s=r+1;s<=13;s++)
                                            {
                                                for(int t=s+1;t<=14;t++)
                                                {
                                                    for(int u=t+1;u<=15;u++)
                                                    {
                                                        for(int v=u+1;v<=16;v++)
                                                        {
                                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t||t==u||u==v)continue;
                                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]+a[u]+a[v]>2*max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]),a[u]),a[v]))cnt++;
                                                            cnt%=mod;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=4;j++)
            {
                for(int k=j+1;k<=5;k++)
                {
                    for(int l=k+1;l<=6;l++)
                    {
                        for(int m=l+1;m<=7;m++)
                        {
                            for(int o=m+1;o<=8;o++)
                            {
                                for(int p=o+1;p<=9;p++)
                                {
                                    for(int q=p+1;q<=10;q++)
                                    {
                                        for(int r=q+1;r<=11;r++)
                                        {
                                            for(int s=r+1;s<=12;s++)
                                            {
                                                for(int t=s+1;t<=13;t++)
                                                {
                                                    for(int u=t+1;u<=14;u++)
                                                    {
                                                        for(int v=u+1;v<=15;v++)
                                                        {
                                                            for(int w=v+1;w<=16;w++)
                                                            {
                                                            if(i==j||j==k||k==l||l==m||m==o||o==p||p==q||q==r||r==s||s==t||t==u||u==v||v==w)continue;
                                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[s]+a[t]+a[u]+a[v]+a[w]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s]),a[t]),a[u]),a[v]),a[w]))cnt++;
                                                            cnt%=mod;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[16]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[16]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[16]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[16]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[16]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[16]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[16]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[16]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[16]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[16]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[16]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[16]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[16]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[16]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[16]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[16]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[16]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[16]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[16]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[16]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[16]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[16]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[16]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[16]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[16]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[16]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[16]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[16]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[16]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[16],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]))cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>2*max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]),a[11]),a[12]),a[13]),a[14]),a[15]),a[16]))cnt++;
        cnt%=mod;
        cout<<cnt;
    }
    return 0;
}
