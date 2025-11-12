#include<bits/stdc++.h>
using namespace std;
int n,num,maxx;
int a[3][100005],b[3];
void dfs(int dep)
{
    if(dep-1==n)
    {
        if(b[0]<=n/2&&b[1]<=n/2&&b[2]<=n/2)
        {
            maxx=max(num,maxx);
            return;
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            num+=a[i][dep];
            b[i]++;
            dfs(dep+1);
            num-=a[i][dep];
            b[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        num=0,maxx=0;
        b[0]=0,b[1]=0,b[2]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[0][i]>>a[1][i]>>a[2][i];
        }
        dfs(1);
        cout<<maxx<<endl;
    }
    return 0;
}
