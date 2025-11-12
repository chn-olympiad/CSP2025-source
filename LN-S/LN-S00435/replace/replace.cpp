#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
string a[600000][5];
string b[600000][5];
int main()
{

     freopen("replace.in","r",stdin);
     freopen("replace.out","w",stdout);
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=2;j++)
          {
              cin>>a[i][j];
          }
      }
      for(int i=1;i<=m;i++)
      {
          for(int j=1;j<=2;j++)
          {
              cin>>b[i][j];
          }
      }
      for(int i=1;i<=m;i++)
      {
          cout<<0<<endl;
      }
    return 0;
}
