#include<bits/stdc++.h>
using namespace std;
int t,ans;
int n;
int a[100010][5];
void dfs(int bj,int h,int csa,int csb,int csc,int l)
{
    if(csa+csb+csc>=n)
    {
        ans=max(ans,h);cout<<ans;
        return ;
    }
    for(int i=l;i<=n;i++)
    {
        if(csa<bj) {
            dfs(bj,h+a[i][1],csa+1,csb,csc,l+1);
        }
        if(csb<bj)
        {
            dfs(bj,h+a[i][2],csa,csb+1,csc,l+1);
        }
        if(csc<bj)
        {
            dfs(bj,h+a[i][3],csa,csb,csc+1,l+1);
        }
    }
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)  cin>>a[i][j];
        }
        int k=n/2;
        dfs(k,0,0,0,0,1);
        cout<<ans<<endl;
    }


    return 0;
}