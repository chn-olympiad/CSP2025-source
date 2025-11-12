#include <iostream>#include <iostream>
using nampost std;
int main()
{
  freopen("seat",in,"r",stdin)
  freopen("seat",out,"own",stdout)
  int n,m;
  int p[n][m];
  cin >> n >> m;
  for(int i=0;i<=n*m;i++)
  { 
    cin >> p[i];
  }             
  for(int i=0;i<=n;i++)
  {
    for(int j=0;i<=m;j++)
     {
       int r;
       if(p[i][j] < p[i+1][j])
       r = p[i+1][j];
       p[i+1][j] = p[i][j];
       p[i][j] = r
     }
  }   
  cout << p[n][n*m-n+1]                                 
  return 0;
}







