#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

int n,m;
int a[105],b[15][15];
int d;

bool cmp(int x,int y)
{
    return x>y;

}

void seat()
{
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                b[i][j]=a[(i-1)*n+j];
                if(b[i][j]==d)
                {
                    cout<<i<<" "<<j<<endl;
                    return;
                }
            }

        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                b[i][j]=a[(i-1)*n+n-j+1];
                if(b[i][j]==d)
                {
                    cout<<i<<" "<<j<<endl;
                    return;
                }
            }

        }

    }

}


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cnt++;
            cin>>a[cnt];

        }

    }
    d=a[1];
    sort(a+1,a+cnt+1,cmp);
    seat();
    return 0;
}
