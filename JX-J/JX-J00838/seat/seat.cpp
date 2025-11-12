#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[110],b[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,din = 0,sum = 0,l = 1,x = 0,y = 0;
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    din = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i<=m;i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1;j<=n;j++)
            {
                b[j][i] = a[l];
                l++;
                if(b[j][i] == din)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j = n;j>=1;j--)
            {
                b[j][i] = a[l];
                l++;
                if(b[j][i] == din)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
