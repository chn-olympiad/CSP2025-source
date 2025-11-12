#include <bits/stdc++.h>
using namespace std;
int n,m,k,book[1000005],c;
long long a[100005][100005],minn=1e17;
void dfs(int x,long long sum)
{
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0 && a[x][i]<=1e9)
        {
            flag=false;
            dfs(i,sum+a[x][i]);
        }
    }
    if(flag==true)
        minn=min(minn,sum);
    return ;
}
int main()
{
	 freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
     memset(a,0x4f,sizeof a);
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y>>a[x][y];
        a[y][x]=a[x][y];
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=n;j++)
            cin>>x;
    }
    dfs(1,0);
    cout<<minn;
	return 0;
}
