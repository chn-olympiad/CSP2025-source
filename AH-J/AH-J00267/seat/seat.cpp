#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m;
  int x[103];
  int tmp;
  int h,l;
  int r;
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)
  {
	  cin>>x[i];
  }
  r=x[1];
  int R=r;
  sort(x+1,x+n*m+1);
  for(int i=1;i<=n*m;i++)
  {
	  if(R==x[i])tmp=n*m-i+1;
  }
  if(tmp%n==0)l=tmp/n;
  else l=tmp/n+1;
  if(l%2!=0)
  {
	  if(tmp%n==0)h=n;
	  else h=tmp%n;
  }
  else
  {
	  if(tmp%n==0)h=1;
	  h=n-tmp%n+1;
  }
  cout<<l<<' '<<h;
  return 0;
}
