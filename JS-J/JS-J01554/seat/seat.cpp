#include<bits/stdc++.h>
using namespace std;
int n,m,p;
pair<int,int>a[10001];
int cmp(pair<int,int>x,pair<int,int>y)
{
    return x.second>y.second;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i].second,a[i].first=i;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m*n;i++)
    {
        if(a[i].first==1)
        {
            p=i;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=n;j++)
            {
                if((i-1)*n+j==p)
                {
                    cout<<i<<" "<<j<<"\n";
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                if((i-1)*n+n-j+1==p)
                {
                    cout<<i<<" "<<j<<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
