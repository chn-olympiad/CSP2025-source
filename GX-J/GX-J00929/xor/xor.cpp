#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  int n,k;
  cin>>n>>k;
  int a[500001];
  for(int i=1;i<=n;i++)
  {
	int x;
	cin>>x;
	a[i]=x;  
  }
  return 0;
}
