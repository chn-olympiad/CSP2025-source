#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct DATA{
  long long a,b,c;
}a[N];
bool cmpa(DATA a,DATA b)
{
  return a.a-max(a.b,a.c)<b.a-max(b.b,b.c);  
}
bool cmpb(DATA a,DATA b)
{
  return a.b-max(a.a,a.c)<b.b-max(b.a,b.c);  
}
bool cmpc(DATA a,DATA b)
{
  return a.c-max(a.a,a.b)<b.c-max(b.a,b.b);  
}
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  while(t--)
  {
  long long x=0,y=0,z=0;
  DATA xn[N],yn[N],zn[N];
  int ans=0;
	memset(a,0,sizeof a);
	memset(xn,0,sizeof xn);
	memset(yn,0,sizeof yn);
	memset(zn,0,sizeof zn);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
		cin>>a[i].a>>a[i].b>>a[i].c;
    int maxn=max(a[i].a,max(a[i].b,a[i].c));
    if(maxn==a[i].a) x++,xn[x]=a[i],ans+=xn[x].a;
    else if(maxn==a[i].b) y++,yn[y]=a[i],ans+=yn[y].b;
    else if(maxn==a[i].c) z++,zn[z]=a[i],ans+=zn[z].c;
   }
  if(x>n/2) 
  {
	sort(xn+1,xn+1+x,cmpa);
    for(int j=1;j<=x-(n/2);j++)
    ans=ans-xn[j].a+max(xn[j].b,xn[j].c);
  }
  
  else if(y>n/2) 
  {
	sort(yn+1,yn+1+y,cmpb);
    for(int j=1;j<=y-(n/2);j++)
    ans=ans-yn[j].b+max(yn[j].a,yn[j].c);
  }
  else if(z>n/2) 
  {
	sort(zn+1,zn+1+z,cmpc);
    for(int j=1;j<=z-(n/2);j++)
     ans=ans-zn[j].c+max(zn[j].a,zn[j].b);
  }
  cout<<ans<<endl;
  }
  return 0;
}
