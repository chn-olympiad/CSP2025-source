#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  char a[101],b[101],c[101];
  int sum;
  cin>>a;
  for(int i=1;i<=strlen(a);i++)
  {
    if('0'<=a[i]<='9')
      b[i]=a[i];
    sum=strlen(b);
  }
  sort(b+1,b+sum+1);
  for(int i=strlen(c);i>=1;i++)
    cout<<c[i];
  return 0;
}
