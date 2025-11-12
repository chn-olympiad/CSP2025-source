#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=100005;
int T;
int n,a[N][4],f[N],s[N];
int x=0,y=0,z=0;
ll ans=0;
bool cmp(int a,int b)
{
   return a<b;
}
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   scanf("%d",&T);
   while(T--)
   {
      scanf("%d",&n);
      memset(f,0,sizeof(f));
      memset(s,0x3f3f3f,sizeof(s));
      ans=0;
      x=0,y=0,z=0;
      for(int i=1;i<=n;i++)
      {
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        int p=max(a[i][1],max(a[i][2],a[i][3]));
        ans+=p;
        if(a[i][1]==p) {x++; f[i]=1; continue;}
        if(a[i][2]==p) {y++; f[i]=2; continue;}
        if(a[i][3]==p) {z++; f[i]=3; continue;}
      }
      int k=0,t=0;
      if(x<=n/2 && y<=n/2 && z<=n/2) {cout<<ans<<endl; continue;}
      if(x>n/2) {k=1; t=x-n/2;}
      if(y>n/2) {k=2; t=y-n/2;}
      if(z>n/2) {k=3; t=z-n/2;}
      for(int i=1;i<=n;i++)
      {
        if(f[i]!=k) continue;
        int m=0;
        for(int j=1;j<=3;j++)
        {
          if(j==k) continue;
          if(m<a[i][j]) m=a[i][j];
        }
        s[i]=a[i][k]-m;
      }
      sort(s+1,s+n+1,cmp);
      for(int i=1;i<=t;i++)
        ans-=s[i];
      cout<<ans<<endl;
   }
   return 0;
}
