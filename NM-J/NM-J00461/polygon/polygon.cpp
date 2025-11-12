#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,a[5005],b[5005],vis[5005];
long long ans=0;
long long jie(int x,int y)
{
    long long nm=1,nm2=1;
    for(int i=1;i<=y;i++)
    {
        nm=((nm%MOD)*(i%MOD))%MOD;
    }
    for(int i=x-y+1;i<=x;i++)
    {
        nm2=((nm2%MOD)*(i%MOD))%MOD;
    }
    return nm2/nm;
}

void dfs(int x,int nums,int y)
{
    if(nums==x)
    {
        int maxxx=-1;
        int numss=0;
        for(int i=1;i<=x;i++)
        {
            //cout<<b[i]<<endl;
            if(b[i]>maxxx)
            {
                maxxx=b[i];
            }
            if(i>=2&&(b[i]<b[i-1]))
            {
                return;
            }
            numss+=b[i];
        }
        //cout<<endl;
        if(numss>(maxxx*2))
        {
            ans++;
        }
    }

    for(int i=nums+1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            b[y]=a[i];
            dfs(x,nums+1,y+1);
            vis[i]=0;
        }
    }

}

int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    int maxx=-1;
    int nums=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>maxx)
        {
            maxx=a[i];
        }
        if(a[i]==1)
        {
            nums++;
        }
    }
    if(n==3)
    {
        if((a[1]+a[2]+a[3])>(maxx*2))
        {
            ans=((ans%MOD)+1)%MOD;
        }
    }

    else if(nums==n)
    {
        for(int i=3;i<=n;i++)
        {
            if(i>n-i)
            {
                ans=((ans%MOD)+(jie(n,n-i)%MOD))%MOD;
            }
            else
            {
                ans=((ans%MOD)+(jie(n,i)%MOD))%MOD;
            }

        }
    }
    else
    {
        for(int i=3;i<=n;i++)
        {
            dfs(i,0,1);
            //cout<<ans<<endl;
            //ans=(ans%MOD)+()%MOD);
        }
    }

    cout<<ans;
    return 0;
}
