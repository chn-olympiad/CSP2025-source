#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,b[500005],c[500005],e[500005],pp=0;
void dfs(long long j)
{

    if(j==n)
    {

        pp=max(pp,sum);
        sum=0;
        return ;
    }


    if(c[j]!=k&&j<n+1&&e[j]==0)
    {
        dfs(j+1);
    }

    if(j>n)
    {

        e[j]++;
        sum=0;
        return ;
    }

    for(long long i=j;i<=n;i++)
    {
        c[i]=b[i] ^ b[j];
    }
    sum++;
    dfs(j+1);




}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2)
        {
            b[i]=a[i-1]^a[i];
            c[i]=b[i];
        }
        else
        {
            b[i]=a[i];
            c[i]=b[i];
        }
    }
    dfs(1);
    cout<<pp;
    return 0;
}
