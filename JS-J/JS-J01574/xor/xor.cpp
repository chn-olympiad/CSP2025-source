#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int cnt=0;
int xorr(int l,int r)
{
    int sum=0;
    for(int i=l+1;i<=r;i++)
    {
        sum+=(a[i]^a[i-1]);
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    bool flag1=true,flag2=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) flag1=false;
        if(a[i]!=1&&a[i]!=0) flag2=false;
    }
    if(flag1==true)
    {
        if(k==1)
        {
            cout<<n<<'\n';
            return 0;
        }
        if(k==0)
        {
            cout<<n/2<<'\n';
            return 0;
        }
        if(k!=1&&k!=0)
        {
            cout<<0<<'\n';
            return 0;
        }
        return 0;
    }
    if(flag2==true)
    {
        bool flag[500010];
        memset(flag,true,sizeof(flag));
        int sum0=0;
        int sum1=0;
        int sumtp=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) sum0++;
            if(a[i]==1) sum1++;
        }
        if(k==1)
        {
            cout<<sum1<<'\n';
            return 0;
        }
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1&&a[i+1]==1&&flag[i]==true&&flag[i+1]==true)
                {
                    sumtp++;
                    flag[i]=false;
                    flag[i+1]=false;
                }
            }
            cout<<sumtp+sum0<<'\n';
            return 0;
        }
    }
    if(flag1==false&&flag2==false)
    {
         for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(xorr(i,j)==k) cnt++;
            }
        }
        cout<<cnt+1<<endl;
        return 0;
    }
    return 0;
}
