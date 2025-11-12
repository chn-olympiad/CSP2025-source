#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[110];
int n,m;
int main()
{
    freopen("seat3.in","r",stdin);
    freopen("seat3.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin>>b[i];
    }
    int k=b[1];
    sort(b,b+x+1);
    int q=0;
    for(int i=1;i<=m;i++)
    {

        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=b[x-q];
                q++;
            }
        }
        if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                a[i][j]=b[x-q];
                q++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==k)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }

}
