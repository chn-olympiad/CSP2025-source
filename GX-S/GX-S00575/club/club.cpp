#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long t,n;
struct love
{
  int x,y,z;
  int fx,fy,fz;
}a[10001];
bool cmp1(love q,love p)
{
  return q.x>p.x;
}
bool cmp2(love q,love p)
{
  return q.y>p.y;
}
bool cmp3(love q,love p)
{
  return q.z>p.z;
}
int ans;
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  while(t--)
  {
    cin >>n;
    for(int i=1; i<=n; i++)
      cin >>a[i].x>>a[i].y>>a[i].z;
    sort(a+1,a+n+1,cmp1);
    for(int i=1; i<=n/2; i++)
      a[i].fx=1;
    sort(a+1,a+n+1,cmp2);
    for(int i=1; i<=n/2; i++)
      a[i].fy=1;
    sort(a+1,a+n+1,cmp3);
    for(int i=1; i<=n/2; i++)
      a[i].fz=1;
    for(int i=1; i<=n; i++)
    {
        if(a[i].fx==1&&a[i].fy==1&&a[i].fz==1)
          ans+=max(a[i].x,max(a[i].z,a[i].y));
        else
        {
          if(a[i].fx==1&&a[i].fy==1)
            ans+=max(a[i].fx,a[i].fy);
          else
          {
            if(a[i].fx==1&&a[i].fz==1)
              ans+=max(a[i].fx,a[i].fz);
            else
            {
              if(a[i].fy==1&&a[i].fz==1)
                ans+=max(a[i].fy,a[i].fz);
              else
              {
                if(a[i].fx==1)
                  ans+=a[i].fx;
                else
                {
                  if(a[i].fy==1)
                    ans+=a[i].fy;
                  else
                    if(a[i].fz==1)
                      ans+=a[i].fz;
                }
              }
            }
          }
        }
    }
    cout <<ans<<endl;
    for(int i=1; i<=n; i++)
    {
      a[i].fx=0;
      a[i].fy=0;
      a[i].fz=0;
    }
  }
  return 0;
}
