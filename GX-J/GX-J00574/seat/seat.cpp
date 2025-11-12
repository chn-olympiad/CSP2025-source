#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1086];
bool cmp(int x,int y)
{
    return y<x;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sum;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            sum=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int u=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[u]==sum)
            {
                cout<<i<<" ";
                if(i/2==0)
                {
                    cout<<n-j+1;
                }
                else
                {
                    cout<<j;
                }
                return 0;
            }
            u++;
        }
    }
    return 0;
}
