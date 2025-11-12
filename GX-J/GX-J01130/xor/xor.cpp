#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXX=5*100000+100,dob=20+10;
int a[MAXX],s[MAXX],n,k;int l,r,xp;
int xx[dob],yy[dob];
struct kb
{
	int l,r;
}sum[MAXX];
void zero(int x)
{
	  for(int i=1;i<=dob;i++)
	  {xx[i]=x;yy[i]=x;}
	  return ;
}
int zdy(int x,int y)
{
  zero(0);
  int l1=0,l2=0,an=0,nu=1;
  int t=x;
  while(t)
  {
	 xx[++l1]=t%2;
	 t/=2; 
  }
  t=y;
  while(t)
  {
	 yy[++l2]=t%2;
	 t/=2;
  }
  for(int i=1;i<=max(l1,l2);i++)
  {
	  if(xx[i]!=yy[i])xx[i]=1;
	  else xx[i]=0;
  }
  for(int i=1;i<=max(l1,l2);i++)
  {
	  if(xx[i]==1)an+=nu;
	  nu*=2;
  }
  //for(int i=1;i<=max(l1,l2);i++)cout<<xx[i];
  //cout<<endl<<max(l1,l2)<<endl;
  return an;
}
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++){cin>>a[i];}
  for(l=1;l<=n;l++)
  {
	  r=l;int z=a[l];
	  while(z<=k && r<=n)
	  {
		  if(r!=l)z=zdy(z,a[r]);
		  //cout<<l<<" "<<r<<" "<<z<<endl;
		  if(z==k)
		  {
			  //cout<<endl<<sum[xp].l<<" "<<sum[xp].r;
			  if(r<=sum[xp].r)
			  {
				  sum[xp].l=l;sum[xp].r=r;//cout<<"==";
			  }
			  else
			  if(l>sum[xp].r)
			  {
				  xp=xp+1;sum[xp].l=l;sum[xp].r=r;//cout<<"++";
			  }
			  //cout<<sum[xp].l<<" "<<sum[xp].r<<" "<<xp;
		  }
		  r++;
		  //cout<<endl;
	  }
  }
  cout<<xp;
  return 0;
}
