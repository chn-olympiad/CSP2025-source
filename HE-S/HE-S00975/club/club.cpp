#include <bits/stdc++.h>
using namespace std;
long long a[5][5],x,xx,xxx,xxxx,xxxxx,xxxxxx,xxxxxxx,xxxxxxxx,ans,t,n;
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);  
  cin>>t;
  for(int i=1;i<=t;i++)
  {
  	x=0;
  	xx=0;
  	xxx=0;
  	xxxx=0;
  	xxxxx=0;
  	xxxxxx=0;
  	xxxxxxx=0;
  	xxxxxxxx=0;
  	n=0;
  	ans==0;
  	cin>>n;
  	for(int j=1;j<=2;j++)
  	{
  	  cin>>a[1][j]>>a[2][j]>>a[3][j];
	}
	x=a[1][1]+a[2][1];
	xx=a[1][1]+a[2][2];
	xxx=a[1][1]+a[3][1];
	xxxx=a[1][1]+a[3][2];
	xxxxx=a[1][2]+a[2][1];
	xxxxxx=a[1][2]+a[2][2];
	xxxxxxx=a[1][2]+a[3][1];
	xxxxxxxx=a[1][2]+a[3][2];
	ans=max(ans,x);
	ans=max(ans,xx);
	ans=max(ans,xxx);
	ans=max(ans,xxxx);
	ans=max(ans,xxxxx);
	ans=max(ans,xxxxxx);
	ans=max(ans,xxxxxxx);
	ans=max(ans,xxxxxxxx);
	cout<<ans<<endl;
  }
  
  return 0;
} 
