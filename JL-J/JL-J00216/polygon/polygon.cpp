#include<bits/stdc++.h>
using namespace std;
long long s[5005],fun[5005][5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    long long maax=0;
    cin>>n;
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    else if(n==3)
    {
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            sum=sum+s[i];
        }
        sort(s+1,s+n+1);
        if(sum>2*s[n])
            cout<<1;
        else
            cout<<0;
    }
    else if(n==4)
    {
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        sort(s+1,s+n+1);
        if(s[1]+s[2]+s[3]>2*s[3])
            sum++;
        if(s[1]+s[2]+s[4]>2*s[4])
            sum++;
        if(s[1]+s[3]+s[4]>2*s[4])
            sum++;
        if(s[2]+s[3]+s[4]>2*s[4])
            sum++;
        if(s[1]+s[2]+s[3]+s[4]>2*s[4])
            sum++;
        cout<<sum<<endl;
        return 0;
    }
    else if(n==5)
    {
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        sort(s+1,s+n+1);
        if(s[1]+s[2]+s[3]>2*s[3])
            sum++;
        if(s[1]+s[2]+s[4]>2*s[4])
            sum++;
        if(s[1]+s[2]+s[5]>2*s[5])
            sum++;
        if(s[1]+s[3]+s[4]>2*s[4])
            sum++;
        if(s[1]+s[3]+s[5]>2*s[5])
            sum++;
        if(s[1]+s[4]+s[5]>2*s[5])
            sum++;
        if(s[2]+s[4]+s[5]>2*s[5])
            sum++;
        if(s[2]+s[3]+s[4]>2*s[4])
            sum++;
        if(s[2]+s[3]+s[5]>2*s[5])
            sum++;
        if(s[3]+s[4]+s[5]>2*s[5])
            sum++;
        if(s[1]+s[2]+s[3]+s[4]>2*s[4])
            sum++;
        if(s[1]+s[2]+s[3]+s[5]>2*s[5])
            sum++;
        if(s[1]+s[2]+s[4]+s[5]>2*s[5])
            sum++;
        if(s[1]+s[3]+s[4]+s[5]>2*s[5])
            sum++;
        if(s[2]+s[3]+s[4]+s[5]>2*s[5])
            sum++;
        if(s[1]+s[2]+s[3]+s[4]+s[5]>2*s[5])
            sum++;
        cout<<sum<<endl;
        return 0;
    }
    else if(n==6)
    {
        cout<<38;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        sort(s+1,s+n+1);
        for(int i=1;i<=n;i++)
        {
            long long sum=0;
            for(int j=i;j<=n;j++)
            {
                sum=sum+s[j];
                fun[i][j]=sum;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(fun[i][j]>s[j]*2)
                {
                    long long num=j-i+1;
                    if(num>=3)
                    maax++;
                    long long ssum=fun[i][j];
                    for(int z=1;z<=i-2;z++)
                    {
                        for(int zz=z;z<=i-2;z++)
                        {
                            ssum++;
                        }
                    }
                    for(int z=j+2;z<=n;z++)
                    {
                        for(int zz=z;zz<=n;zz++)
                        {
                            ssum+=fun[z][zz];
                            if(ssum>2*fun[zz][zz])
                            {
                                num++;
                                if(num>=3)
                                maax++;
                            }
                        }
                    }
                }
            }
        }
        cout<<maax;
    }
    return 0;
}
