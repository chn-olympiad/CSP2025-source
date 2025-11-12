#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

struct node
{
    int g1,g2,g3;
};
node a[N];
int n,ans = 0;

void dfs(int cur, int c1, int c2, int c3, int sum)
{
    if(c1 > n/2 || c2>n/2 || c3>n/2)
    {
        return;
    }
    if(cur > n)
    {
        ans = max(ans,sum);
        return;
    }
    dfs(cur+1,c1+1,c2,c3,sum+a[cur].g1);
    dfs(cur+1,c1,c2+1,c3,sum+a[cur].g2);
    dfs(cur+1,c1,c2,c3+1,sum+a[cur].g3);
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool f1 = 1, f2 = 1;
        for(int i = 1; i<= n; i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            a[i].g1 = x, a[i].g2 = y, a[i].g3 = z;
        }
        ans = 0;
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
