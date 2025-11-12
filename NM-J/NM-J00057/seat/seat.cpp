#include<bits/stdc++.h>
using namespace std;
int a[110];
int b,n,m,yy,y,xx,ans;
bool cmp(int a,int b)
{return a>b;
}
int main()
{  freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
  cin>>n>>m;
  int w=n*m;
  cin>>yy;
  for(int i=1;i<w;i++)
    cin>>a[i];
 sort(a+1,a+1+w,cmp);
// for(int i=1;i<=n;i++)
  //  for(int j=1;j<=m;j++)

 for(int i=1;i<w;i++)
   if(yy<a[i]&&yy>a[i+1]) ans=i+1;
 if(yy>a[1])ans=1;
   else if(yy<a[w-1])ans=w;
 if(ans%n==0)y=ans/n;
    else y=ans/n+1;
 if(y%2==0) xx=y*n-ans+1;
   else  xx=ans-(y-1)*n;
 cout<<y<<' '<<xx;


  return 0;
}

// 100   98 97
// 99
