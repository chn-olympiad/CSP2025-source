#include <bits/stdc++.h>
using namespace std;
int n;
int f[10005];
int a[5005];
int sum;
int maxn;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f[x]++;
        if(f[x]>1) f[x]=1;
        a[i]++;
        maxn=max(maxn,x);
        sum+=x;
    }
    //f[0]=1;
    /*for(int i=1;i<=sum-maxn;i++){
        for(int j=0;j<(i>maxn?maxn+1:i);j++)
        {
            f[i+j]+=f[j];
        }
        if(f[i]>1) f[2*i]+=f[i]-1;
    }
   /* for(int i=1;i<=5005;i++)
    {
        if(a[i]!=0)
        {
            for(int j=sum;j>=i;j--)
            {
                for(int l=1;l<=a[i];l++)
                {
                    f[j]+=f[j-l*i];
                }
            }
        }
    }*/
    //for(int i=1;i<=20;i++) cout<<f[i]<<' ';
    if(sum>2*maxn) cout<<1;
    else cout<<0;
    return 0;
}
