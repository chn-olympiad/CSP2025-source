#include <iostream>
#include <cstdio>
using namespace std;
int sum=0,a[5001],n,use[5001],nn;
bool book[5001],scnt=0;
int j(int a)
{
	int cn=1;
	for(int i=2;i<=a;i++)
	  cn*=i;
	return cn;
}
int gcd(int a)
{
	return j(a)/j(a-1);
}
int themax(int b[],int x)
{
	int max=-1;
	for(int i=1;i<=x;i++)
	  if(b[i]>max)
	    max=b[i];
	return max;
}
bool iscan(int b[],int x)
{
	int cnt=0;
	for(int i=1;i<=x;i++)
	  cnt+=b[i];
	if(cnt>themax(b,x)*2)
	  return true;
	return false;
}
void dfs(int need,int booknum)
{
	if(booknum>need)
	  return;
	if(booknum==need)
	{
	  if(iscan(use,need))
	    scnt++;
	  return;
	}
	for(int i=1;i<=n;i++)
	{
	  if(!book[i])
	  {
	  	book[i]=true;
	  	use[++nn]=a[i];
	  	dfs(need,nn);
	  	nn--;
	  	book[i]=false;
	  }
	}
}
void work()
{
	for(int i=3;i<=n;i++,nn=0)
	{
	  scnt=0;
	  dfs(i,0);
	  sum+=scnt/gcd(scnt);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	if(n==3)
	{
	  int cnt=0;
	  for(int i=1;i<=3;i++)
	    cnt+=a[i];
	  if(cnt>themax(a,3)*2)
	  {
	    cout<<1;
	    return 0;
	  }
	  cout<<0;
	  return 0;
	}
	work();
	cout<<sum%998224353;
	return 0;
}
