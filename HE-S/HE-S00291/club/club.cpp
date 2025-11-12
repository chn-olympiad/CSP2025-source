#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int t,n; 
int yi,er,san;
int a[100010][10];
struct pp
{
	int place;
	int go;
	int pw;
}g[300010];
bool cmp(pp aa,pp bb)
{
	return aa.pw<bb.pw;
}
bool tea=true;
bool teb=true;
int tea_[100010];
long long ans1=0;
void dfs(int now,long long sum,int ren1,int ren2,int ren3)
{
	if(now>n)
	{ 
		ans1=max(ans1,sum);
		return ;
	}
	int can=n/2;
	if(ren1<can)
	{//能去1 
		dfs(now+1,sum+a[now][1],ren1+1,ren2,ren3);
	}
	if(ren2<can)
	{//能去2 
		dfs(now+1,sum+a[now][2],ren1,ren2+1,ren3);
	}
	if(ren3<can)
	{//能去3 
		dfs(now+1,sum+a[now][3],ren1,ren2,ren3+1);
	}
}
int sun_go_1[100010];
int sun_go_2[100010];
bool coke(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//记得解注释!!!!!!!
	
	//有一点思路了
	//先全部放到效益最大的那一边
	//如此只会有至多一边超过限制
	//再按照效益从小到大将其安排在剩下两个中 
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans1=0;
		long long ans=0;
		yi=0;
		er=0;
		san=0;
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int z=1;z<=3;z++)
			{
				cin>>a[i][z];
				if(z==2)
				{
					if(a[i][z]!=0)
					{
						tea=false;
					}
				}
				if(z==3)
				{
					if(a[i][z]!=0)
					{
						tea=false;
						teb=false;
					}
				}
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				yi++;
				ans+=a[i][1];
				cnt++;
				g[cnt].place=1;
				g[cnt].go=2;
				g[cnt].pw=a[i][1]-a[i][2];
				cnt++;
				g[cnt].place=1;
				g[cnt].go=3;
				g[cnt].pw=a[i][1]-a[i][3];
				cnt++;
				g[cnt].place=1;
				g[cnt].go=1;
				g[cnt].pw=200000000;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				er++;
				ans+=a[i][2];
				cnt++;
				g[cnt].place=2;
				g[cnt].go=1;
				g[cnt].pw=a[i][2]-a[i][1];
				cnt++;
				g[cnt].place=2;
				g[cnt].go=3;
				g[cnt].pw=a[i][2]-a[i][3];
				cnt++;
				g[cnt].place=2;
				g[cnt].go=2;
				g[cnt].pw=200000000;
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
			{
				san++;
				ans+=a[i][3];
				cnt++;
				g[cnt].place=3;
				g[cnt].go=1;
				g[cnt].pw=a[i][3]-a[i][1];
				cnt++;
				g[cnt].place=3;
				g[cnt].go=2;
				g[cnt].pw=a[i][3]-a[i][2];
				cnt++;
				g[cnt].place=3;
				g[cnt].go=3;
				g[cnt].pw=200000000;
			}
		}
		if(tea)
		{
			for(int i=1;i<=n;i++)
			{
				tea_[i]=a[i][1];
			}
			sort(tea_+1,tea_+1+n,coke);
			long long suan=0;
			for(int i=1;i<=n/2;i++)
			{
				suan+=tea_[i];
			}
			cout<<suan<<'\n';
		}
		else if(n<=30)
		{
		dfs(1,0,0,0,0);
		cout<<ans1<<'\n';	
		}
		else if(teb)
		{//先都放在对于自己来说效益最大的地方
		//然后按照效益损失从小到大 把多出的一方向另一方放人 
		int yi1=0;
		int er1=0;
		long long suanb=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2])
			{//放1更好 
				yi1++;	
				suanb+=a[i][1];
				sun_go_2[i]=a[i][1]-a[i][2];
				sun_go_1[i]=20000000;
			}
			else
			{
				er1++;	
				suanb+=a[i][2];
				sun_go_1[i]=a[i][2]-a[i][1];
				sun_go_2[i]=20000000;
			}
		}
		int geshu=1;	
		if(yi1>er1)
		{
			sort(sun_go_2+1,sun_go_2+1+n);
			while(yi1>er1)
			{
				yi1--;
				er1++;
				suanb-=sun_go_2[geshu];
				geshu++;
			}
		}
		else if(yi1<er1)
		{
			sort(sun_go_1+1,sun_go_1+1+n);
			while(er1>yi1)
			{
				er1--;
				yi1++;
				suanb-=sun_go_1[geshu];
				geshu++;
			}
		}
		cout<<suanb<<'\n';
		}
		else
		{
		sort(g+1,g+1+cnt,cmp);
		int ji=1;
		if(san>n/2)
		{
			while(san>n/2)
			{
				if(g[ji].place==3)
				{
					if(g[ji].go==1)
					{
						if(yi<n/2)
						{
							yi++;
							san--;
							ans-=g[ji].pw;
						}
					}
					else if(g[ji].go==2)
					{
						if(er<n/2)
						{
							er++;
							san--;
							ans-=g[ji].pw;
						}
					}
					ji++;
				}
				else
				{
					ji++;
				}
			}
		}
		else if(er>n/2)
		{
			while(er>n/2)
			{
				if(g[ji].place==2)
				{
					if(g[ji].go==1)
					{
						if(yi<n/2)
						{
							yi++;
							er--;
							ans-=g[ji].pw;
						}
					}
					else if(g[ji].go==3)
					{
						if(san<n/2)
						{
							san++;
							er--;
							ans-=g[ji].pw;
						}
					}
					ji++;
				}
				else
				{
					ji++;
				}
			}
		}
		else if(yi>n/2)
		{
			while(yi>n/2)
			{
				if(g[ji].place==1)
				{
					if(g[ji].go==2)
					{
						if(er<n/2)
						{
							er++;
							yi--;
							ans-=g[ji].pw;
						}
					}
					else if(g[ji].go==3)
					{
						if(er<n/2)
						{
							san++;
							yi--;
							ans-=g[ji].pw;
						}
					}
					ji++;
				}
				else
				{
					ji++;
				}
			}	
		}
		cout<<ans<<'\n';
	}	
	}
		
	return 0;
}
