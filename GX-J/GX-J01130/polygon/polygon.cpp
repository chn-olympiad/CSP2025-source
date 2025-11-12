#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXX=5000+10;
int n,a[MAXX],b[MAXX],ans;
bool zdy(long long x,long long y)
{
	return x<y;
}
void sc(int m,int hw,int maxx,int sum,int no)
{
	//cout<<m<<" "<<hw<<" "<<maxx<<" "<<sum<<endl;
	if(hw>m)
	{
		if(maxx*2<sum)
		{
			ans=(ans+1)%998244353;
		}
		return ;
	}
		for(int i=no;i<=n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				sc(m,hw+1,max(maxx,a[i]),sum+a[i],i);
				b[i]=0;
			}
		}
	return ;
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
	  cin>>a[i];
  }
  sort(a+1,a+n+1,zdy);
  for(int i=3;i<=n;i++)
  sc(i,1,0,0,1);
  cout<<ans;
  return 0;
}
