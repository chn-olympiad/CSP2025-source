#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001],ans[5001],ans2[5001],p=0;
void dfs(int n,int r,int k,int pre)
{
    if(k==r+1)
    {
        int s=0;
        for(int i=1;i<=r;i++)
        {
            s=s+ans[i];
        }
        sort(ans2+1,ans2+r+1);
        if(s>2*ans2[r])p++;
        for(int i=1;i<=r;i++)
        ans2[i]=ans[i];
        return;
    }
    for(int i=pre+1;i<=n;i++)
    {
        if(b[i]==0)
        {
            ans[k]=a[i];
            ans2[k]=a[i];
            b[i]=1;
            dfs(n,r,k+1,i);
            b[i]=0;
        }
    }
}
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
        int k=0;
        if(a[1]+a[2]>a[3])k++;
        if(a[1]+a[3]>a[2])k++;
        if(a[2]+a[3]>a[1])k++;
        cout<<k;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        dfs(n,i,1,0);
    }
    cout<<p%998244353;
    return 0;
}
