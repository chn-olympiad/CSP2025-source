#include<bits/stdc++.h>
using namespace std;
int a[500005],ans=0,n,k;
void dfs(int l,int cnt)
{
    int kk=a[l];
    if(kk==k)
    {
        cnt++;
        ans=max(ans,cnt);
        if(l+1<n)   dfs(l+1,cnt);
    }
    if(l+1==n)  return;
    for(int i=l+1;i<n;i++)
    {
        kk=kk^a[i];
        if(kk==k)
        {
            cnt++;
            ans=max(ans,cnt);
            if(i+1<n)   dfs(i+1,cnt);
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        dfs(i,0);
    }
    cout<<ans<<endl;
    return 0;
}

