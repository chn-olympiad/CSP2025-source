#include<bits/stdc++.h>
using namespace std;
int a[120];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int score=a[1];
    int seat=1;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]>score)seat++;
    }
    int sum=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                if(sum>=seat)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
                sum++;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(sum>=seat)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
                sum++;
            }
        }
    }
    return 0;
}
