#include<bits/stdc++.h>
using namespace std;
int arr[500000];
int v[5000000]={0};
long long n,k;
int cnt=0;
void dfs(int l,int r)
{
    if(l>n)
    {
        return;
    }
    if(l<r)
    {
        dfs(r,r);
    }
    for(int i=l;i<=r;i++)
    {
        if(v[i]==1)
        {
            return;
        }
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans^=arr[i];
    }
    if(ans==k)
    {
        cnt++;
        for(int i=l;i<=r;i++)
        {
            v[i]=1;
        }
        dfs(r,r);
        return;
    }
    else
    {
        for(int i=r+1;i<=n;i++)
        {
            if(v[i]==0)
            {
                dfs(l,r+1);
            }
        }
    }
    return;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<arr[1];
        return 0;
    }
    else if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==0)
            {
                cnt++;
            }

        }
        cout<<cnt;
        return 0;
    }
    dfs(1,1);
    if(arr[1]==k) cnt++;
    cout<<cnt;
    return 0;
}
