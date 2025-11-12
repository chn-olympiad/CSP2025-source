#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;

int m,n;
const int N=15;
int a[110],sit[N][N];

bool cmp(int a,int b)
{
    return a>b;
}

signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int pos=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(i%n==0)
        {
            int p=i/n;
            if(p&1)
            {
                sit[n][p]=a[i];
            }
            else
            {
                sit[1][p]=a[i];
            }
        }
        else
        {
            int p=i/n+1,q=i%n;
            if(p&1)
            {
                sit[q][p]=a[i];
            }
            else
            {
                sit[n-q+1][p]=a[i];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(sit[i][j]==pos)
            {
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
