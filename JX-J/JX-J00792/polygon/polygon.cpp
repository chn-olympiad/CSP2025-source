#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.ans","w",stdout);
  int n,s=0,answer=0,m=0,ss=3;
  cin>>n;
  for (int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  while (2*s>m)
  {
      if (ss==3)
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
          s=s+a[i];
      m=max(a);
      answer++;
  }
  cout<<answer<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
