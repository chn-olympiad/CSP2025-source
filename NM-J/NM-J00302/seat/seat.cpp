#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=1;
    cin>>n>>m;
    int a[n][m],b[n*m];

    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m-i-1;j++)
        {

        }
    }
    for(int i=1;i<=m;i++)
    {
        if(x>n)
        {
           x+=m;
            for(int j=1;j<=n;j++)
            {
                b[x]=a[i][j];
                x--;
            }
        }
        else{
            for(int j=1;j<=n;j++)
            {
                b[x]=a[i][j];
                x++;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
