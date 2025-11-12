#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
bool spea=1,speb=1;
int n,k,ans,a[N],sum[N][8];
bool b[N][8];
bool is(int l,int r)
{
    int pwr=0;
    //cout<<l<<" "<<r<<endl;
    for(int i=7;i>=0;i--)
    {
        int w=sum[r][i]-sum[l-1][i];
        if(w%2==1)
        {
            pwr+=pow(2,i);
        }
        //cout<<w<<" ";
    }
    //cout<<endl;
    //cout<<pwr<<endl;
    if(pwr==k)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)spea=0;
        if(a[i]!=1&&a[i]!=0)speb=0;
    }
    if(spea)
    {
        if(k>1)
        {
            cout<<0;
        }
        else if(k==1)
        {
            cout<<n;
        }
        else if(k==0)
        {
            cout<<n/2;
        }
        return 0;
    }
    if(speb)
    {
        if(k>1)
        {
            cout<<0;
        }
        else if(k==1)
        {
            ll ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    ans++;
                }
            }
            cout<<ans;
        }
        else if(k==0)
        {
            ll ans=0,sum=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    ans++;
                }
                if(a[i]==1)
                {
                    if(sum==0)
                    {
                        sum++;
                    }
                    else
                    {
                        sum=0;
                        ans++;
                    }
                }
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i],l=0;
        while(x)
        {
            b[i][l++]=x%2;
            x/=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=7;j>=0;j--)
        {
            sum[i][j]=sum[i-1][j]+b[i][j];
            //cout<<sum[i][j]<<" ";
        }
        //cout<<endl;
    }
    int l=1,r=1;
    while(r<=n)
    {
        if(is(l,r)==1)
        {
            ans++;
            r++;
            l=r;
        }
        r++;
    }
    cout<<ans;
    //4 0 2 1 0 3
    return 0;
}
