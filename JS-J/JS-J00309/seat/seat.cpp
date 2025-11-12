#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int a[105][105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,idx;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            if(i==1&&j==1)
                idx=x;
            pq.push(x);
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(j%2)
        {
            for(int i=1;i<=n;i++)
            {
                a[i][j]=pq.top();
                pq.pop();
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                a[i][j]=pq.top();
                pq.pop();
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(idx==a[i][j])
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
