#include<bits/stdc++.h>
using namespace std;
int t,n,a[2000][13];
int dfs(int shen,int r1,int r2,int r3,int man)
{
    if(max(max(r1,r2),r3)>n/2)
    {
        return 0;
    }
    if(shen==n)return man;
    return max(max(dfs(shen+1,r1+1,r2,r3,man+a[shen+1][1]),dfs(shen+1,r1,r2+1,r3,man+a[shen+1][2])),dfs(shen+1,r1,r2,r3+1,man+a[shen+1][3]));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        cout<<dfs(0,0,0,0,0)<<endl;
    }
    return 0;
}