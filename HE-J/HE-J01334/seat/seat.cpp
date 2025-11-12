#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],c,wz,r;
int cnt,con;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n*m;i++) 
  {
  	cin>>a[i];
  	if(a[i]==i) cnt++;
  	if(a[i]==n*m-i+1) con++;
  }
  if(cnt==n*m)
  {
  	cout<<m<<" "<<n<<endl;
  	return 0;
  } 
  if(con==n*m)
  {
  	cout<<1<<" "<<1<<endl;
  	return 0;
  } 
  wz=a[1];
  sort(a,a+1+n*m);
  for(int i=n*m;i>=1;i--)
  {
  	if(wz==a[i])
  	{
  	  c=i;
  	  r=i;
  	  break;
	}
  }
  while(c>n) c-=n;
  r=n*m-r+1;
  while(r>n) r-=n;
  cout<<c<<" "<<r<<endl;
  return 0;
}
