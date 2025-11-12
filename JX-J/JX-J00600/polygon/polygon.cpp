#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
int mxx;
void dfs(int ds,int mx,int h,int sl,int dq)
{
    if(dq>n+1) return;
    if(ds<=sl){
        if(mx*2<h){ans=(ans+1)%998244353;}
        return;
    }
    dfs(ds,max(mx,a[dq]),h+a[dq],sl+1,dq+1);
    dfs(ds,mx,h,sl,dq+1);
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mxx=max(mxx,a[i]);
    }
    for(int i=3;i<=n;i++)
    {
        dfs(i,0,0,0,1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
