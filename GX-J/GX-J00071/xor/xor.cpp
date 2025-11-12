#include<bits/stdc++.h>
using namespace std;
long long a[500005],jinzhi[35];
bool v[500005];
long long m_xor(long long x,long long y)
{
    long long sum=0;
    string a,b,c;
    for(int i=31;i>=1;i--)
    {
        if(x>=jinzhi[i])
        {
            x-=jinzhi[i];
            a+="1";
        }
        else a+="0";
        if(y>=jinzhi[i])
        {
            y-=jinzhi[i];
            b+="1";
        }
        else b+="0";
    }
    for(int i=0;i<=a.size()-1;i++)
    {
        if(a[i]=='0'&&b[i]=='0') c+="0";
        if(a[i]=='0'&&b[i]=='1') c+="1";
        if(a[i]=='1'&&b[i]=='0') c+="1";
        if(a[i]=='1'&&b[i]=='1') c+="0";
    }
    for(int i=0;i<=c.size()-1;i++)
    {
        if(c[i]=='1') sum+=jinzhi[31-i];
    }
    return sum;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long sum=0;
    jinzhi[1]=1;
    for(int i=2;i<=31;i++)
        jinzhi[i]=jinzhi[i-1]*2;
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j&&a[i]==k)
            {
                sum++;
                continue;
            }
            else
            {
                long long ssum=a[i];
                bool flag=1;
                for(int k=i+1;k<=j;k++)
                {
                    if(v[k]==0)
                        ssum=m_xor(ssum,a[k]);
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    for(int k=i+1;k<=j;k++)
                    {
                        v[k]=1;
                    }
                    if(ssum==k) sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
