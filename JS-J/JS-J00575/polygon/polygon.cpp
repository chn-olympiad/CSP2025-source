#include<bits/stdc++.h>
using namespace std;
int n;
int a[5003];
int cnt=0;
int ans[5003];
void dfs(int ii,int mx,int al,int zz)
{
    if(al>2*mx&&ii>=3)
    {
        cnt++;
        cnt%=998244353;
        //cout<<ii<<"\n";
    }
    ii++;
    for(int i=zz+1;i<=n;i++)
    {
        ans[ii]=a[i];
        int y=max(mx,a[i]);
        dfs(ii,y,al+a[i],i);
        ans[ii]=0;
    }
    return;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(1,a[i],a[i],i);
    }
    cout<<cnt%998244353;
    return 0;
}
