#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[11][11];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k-i+1;j++)
        {
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
//  for(int i=1;i<=k;i++)
//  {
//      cout<<a[i]<<endl;
//  }
    int p=0;
    for(int i=1;i<=n;i++)
    {
        p++;
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
//              if(r==a[n*m])cout<<i<<" "<<j;
//*             b[i][j]=a[p];
                if(r==a[p])
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
//              cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
                p++;
            }
        }
        if(i%2==0)
        {
            for(int j=m;j>=1;j--)
            {
//              if(r==a[n*m])cout<<i<<" "<<j;
// *            b[i][j]=a[p];
                if(r==a[p])
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
//              cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
                p++;
            }
        }
        p--;
    }
//  for(int i=1;i<=n;i++)
//  {
//      for(int j=1;j<=m;j++)
//      {
//          cout<<b[i][j]<<" ";
//      }
//      cout<<endl;
//   }
    return 0;
}
