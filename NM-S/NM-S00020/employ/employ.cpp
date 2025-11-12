#include<bits/stdc++.h>
using namespace std;

long long nx[1000000],nd[1000000];

void dfs(int n,int m)
{
    int visited[n] == {};
    for(int i=1;i<=n;i++)
    {
        visited[1][i] == {1};
        for(int j=1;j<=m;j++)
        {
            visited[j][i] == {1};
        }
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int sum = 0;

    for(int i=1;i<=n;i++)
    {
        cin >> nd[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> nx[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(nd[i]='1')
        {
            sum++;
        }
        else
        {
            break;
        }
        for(int j=1;j<=i;j++)
        {
            if(nx[j]<i)
            {
                break;
            }
        }
    }
    cout << sum;
    return 0;

}