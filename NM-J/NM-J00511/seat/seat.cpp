#include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[10][10];
int n,m;
int q,w;
int o;
int dfs(int x,int y,int ans)
{
//	cout << y << " " << x << " " << ans << '\n';
    if(ans==o)
    {
        q=x;
        w=y;
        return 0;
    }
    if(x>n || y > m)
        return 0;
    if(x==n&&y==m)
        return 0;
	dfs(x,y+1,ans = b[x][y+1]);
    dfs(x+1,y,ans = b[x+1][y]);
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int ans = n*m;
    for(int i = 1;i<=ans;i++)
        cin >> a[i];
    o = a[1];
    sort(a+1,a+ans+1,cmp);
    for(int i =1;i<=ans;i++)
    {
        if(i%2==1)
        {
            for(int j = 1;j<=m;j++)
            {
                b[i][j]=a[i];
            }

        }
        else
        {
            for(int j = m;j>=1;j--)
            {
                b[i][j]=a[i];
            }
        }
    }
        for(int i =1;i<=ans;i++)
    {
        if(i%2==1)
        {
            for(int j = 1;j<=m;j++)
            {
                cout << b[i][j] <<'\n';
            }

        }
        else
        {
            for(int j = m;j>=1;j--)
            {
                cout << b[i][j] << '\n';
            }
        }
    }
    dfs(0,0,0);
    cout<< q  << " " << w;
	return 0;
}
