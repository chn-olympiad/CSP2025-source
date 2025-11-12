#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long cnt;
void dfs(int ed,int mmax,int sum,int tot,int cur)
{
    if(tot>=ed)
    {
        if(sum>mmax)
        {
            cnt++;
        }
        return ;
    }
    for(int i=cur-1;i>=1;i--)
    {
        dfs(ed,mmax,sum+a[i],tot+1,i);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++)
    {
        for(int j=n;j>=1;j--)
        {
            dfs(i,a[j],0,1,j);
        }
    }
    cout<<cnt%998244353;
    return 0;
}
