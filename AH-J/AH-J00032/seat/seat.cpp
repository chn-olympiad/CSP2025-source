#include<bits/stdc++.h>
using  namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100][100];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
       for(int i=0;i<m;i++)
       {
            cin>>a[i][j];
       }
    }
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<m;i++)
        {
            if(i==1&&j==1) cout<<1<<" "<<1;
            else if(i==n&&j==m) cout<<n<<" "<<m;
            else if(i<=n&&j==1) cout<<n<<" "<<1;
            else if(i==1&&j<=m) cout<<1<<" "<<m;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
