#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m,flag;
int nx,ny;
struct csp
{

  int sc,x,y;
}a[100001];
bool cmp(csp p,csp q)
{
  return p.sc>q.sc;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  int s=n*m;
  for(int i=1;i<=s;i++)
  {
     cin>>a[i].sc;
     if(i==1)
      flag=a[i].sc;
  }
  sort(a+1,a+s+1,cmp);
  for(int i=1;i<=s;i++)
  {
    ny++;
    if(ny==n+1)
    {
      nx++;
      ny=1;
    }
    a[i].x=nx;
    a[i].y=ny;
  }
  for(int i=1;i<=s;i++)
    if(a[i].sc==flag)
  {
    cout<<a[i].x+1<<" "<<a[i].y;
    break;
  }
  return 0;
 }


