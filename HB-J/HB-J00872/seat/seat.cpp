#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //
    int n,m,t;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
          cin>>a[i][j];
      }
    }
    t=a[0][0];
        for(int y = 0;y < m;y++)
        {
            for(int j = 0;j < m;j++)
            {
                if(a[0][j] < a[0][j+1])
                {
                    int p = a[0][j];
                    a[0][j] = a[0][j+1];
                    a[0][j+1] = p;
                }
            }
        }
        for(int y = 0;y < n;y++)
        {
            for(int i = 0;i < n;i++)
            {
                if(a[i][0] < a[i+1][0])
                {
                    int p = a[i][0];
                    a[i][0] = a[i+1][0];
                    a[i+1][0] = p;
                }
            }
        }
    for(int i=0;i<n;i++)
    {
      for(int j=1;j<m;j++)
      {
          cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}
