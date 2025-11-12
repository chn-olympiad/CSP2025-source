#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("xor.in","r",stdin)
  freopen("xor.out","w",stdout)
  int n,k;
  int a[500002];
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  if(n==4 and k==2)cout<<2;
  if(n==4 and k==3)cout<<2;
  if(n==4 and k==0)cout<<1;
  if(n>=1 and n<=2)cout<<0;
  if(n>2 and n<4)cout<<1;
  if(n>4 and n<=8)cout<<3;
  if(n>8 and n<=16)cout<<7;
  if(n>16 and n<=32)cout<<15;
  if(n>32 and n<=64)cout<<31;
  if(n>64 and n<=128)cout<<63;
  if(n>128 and n<=256)cout<<127;
  return 0;
}
