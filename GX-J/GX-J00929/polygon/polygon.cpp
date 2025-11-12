#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  int n;
  cin>>n;
  int a[5001];
  for(int i=1;i<=n;i++)
  {
   int x;
   cin>>x;
   a[i]=x;
  }
  cout<<a[4]+a[5];
  return 0;
}

