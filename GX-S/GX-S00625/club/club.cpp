#include<iostream>
#include<cstdio>
using namespace std;
const int MAXX=100000+10;
int n,t,ans,c[4];
struct zdy
{
	int a[4],b[4],id;
}p[MAXX];
void sc(int x,int y)
{
	if(x>n)
	{
		ans=max(ans,y);
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			if(p[x].b[i]==0&&c[i]+1<=n/2)
			{
				p[x].b[i]=1;c[i]++;
				sc(x+1,y+p[x].a[i]);
				p[x].b[i]=0;c[i]--;
			}
		}
	}
	return ;
}
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  while(t--)
  {
	  cin>>n;
	  c[1]=0,c[2]=0,c[3]=0,ans=0;
	  for(int i=1;i<=n;i++)
	  {
		  cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
		  for(int j=1;j<=3;j++)
		  p[i].b[j]=0;
	  }
	  sc(1,0);
	  cout<<ans<<endl;
  }
  return 0;
}
