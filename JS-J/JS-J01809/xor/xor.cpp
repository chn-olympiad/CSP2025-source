#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,k;
int ansz=0;
int a[500000+3];
int js(int be,int en)
{
    int anss=0;
    for(int i=be;i<=en;i++)
    {
       anss^=a[i];
    }
    return anss;
}
void dfs(int num)
{
    if(num>=n)
    {
        ansz=max(ans,ansz);
        if(num==k)
        {
            ansz++;
        }

    }
    for(int i=num;i<=n;i++)
    {
        if(js(num,i)==k)
        {
            ans++;
            dfs(i+1);
            ans--;
        }
        dfs(i+1);
    }
    return ;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int a=0;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        if(js(1,i)==k) ans++;
        dfs(i+1);
    }
    cout<<ansz<<"\n";
    return 0;
}
