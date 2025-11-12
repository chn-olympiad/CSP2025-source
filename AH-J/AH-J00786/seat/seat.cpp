#include <bits/stdc++.h>
using namespace std;
int n,m,score[1001],k,c,r;
bool cmp(int o,int p)
{
  return o<p; 
}
int M(int x,int y)
{
  if(x%y==0)return y;
  else return x%y;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)cin>>score[i];
  int R=score[1];
  sort(score+1,score+1+n*m,cmp);
  for(int i=1;i<=n*m;i++)
    if(score[i]==R)
    {
      k=n*m-i+1;
      break;
    }
  if(k%n==0)c=k/n;
  else c=k/n+1;
  if(c%2==0)r=n-M(k,n)+1;
  else r=M(k,n);
  cout<<c<<' '<<r;
  return 0;
}
//                   __
//100 99 98 97 96 95 94 93 92
