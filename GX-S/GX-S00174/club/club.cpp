#include<bits/stdc++.h>
using namespace std;
int a[1000001][5],s,c[5],n,f2,f3,maxx=-0xfff;
void dfs(int step,int ns)
{
    if(step==0)
    {
        s=max(s,ns);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(c[i]<n/2)
        {
            c[i]++;
            dfs(step-1,ns+a[step][i]);
            c[i]--;
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        c[1]=0,c[2]=0,c[3]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs(n,0);
        cout<<s<<endl;
        s=0;
    }
    return 0;
}
