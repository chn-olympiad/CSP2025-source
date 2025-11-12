#include<bits/stdc++.h>
using namespace std;
int t,n,a[111111][11],m;
void dfs(int stp,int c1,int c2,int c3,int s)
{
    if(c1>n/2||c2>n/2||c3>n/2) return;
    if(stp>n)
    {
        m=max(m,s);
        return;
    }
    dfs(stp+1,c1+1,c2,c3,s+a[stp][1]);
    dfs(stp+1,c1,c2+1,c3,s+a[stp][2]);
    dfs(stp+1,c1,c2,c3+1,s+a[stp][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n,m=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
        dfs(1,0,0,0,0);
        cout<<m<<endl;
    }
    return 0;
}
