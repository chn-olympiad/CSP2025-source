#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[11][11];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i<=m;j++)
        {
            cin>>a[i][j];
            if(n==1 && m==1)
            {
                cout<<a[i][j];
            }
        }
    }
   return 0;
}
