#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int t,n;
int a[N][5];
int aa[N];
ll ans;
int num[5];

struct Node{
	int id,mw,yuan;//每个人最大值的对应部门，对应最大值，原来的编号 
}ren[N];

bool cmp(Node x,Node y)
{
	return x.mw>y.mw;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool isA=true;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int m=0,maxid=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(m<a[i][j])
				{
					m=a[i][j];
					maxid=j;
				}
				if((j==2 || j==3) && a[i][j]) isA=false;
			}
			ren[i].id=maxid;
			ren[i].mw=m;
			ren[i].yuan=i;
		}
		if(n==2)
		{
			if(ans<a[1][1]+a[2][2]) ans=a[1][1]+a[2][2];
			if(ans<a[1][1]+a[2][3]) ans=a[1][1]+a[2][3];
			if(ans<a[1][2]+a[2][1]) ans=a[1][2]+a[2][1];
			if(ans<a[1][2]+a[2][3]) ans=a[1][2]+a[2][3];
			if(ans<a[1][3]+a[2][1]) ans=a[1][3]+a[2][1];
			if(ans<a[1][3]+a[2][2]) ans=a[1][3]+a[2][2];
			cout<<ans<<"\n";
			continue;
		}
		if(isA)
		{
			for(int i=1;i<=n;i++)
			{
				aa[i]=a[i][1];
			}
			sort(aa+1,aa+n+1);
			for(int i=(n/2+1);i<=n;i++)
			{
				ans+=aa[i];
			}
			cout<<ans<<"\n";
		}
		else
		{
			int nn=n/2;
			sort(ren+1,ren+n+1,cmp);
			memset(num,0,sizeof num);
			for(int i=1;i<=n;i++)
			{
				int ww=ren[i].mw,idd=ren[i].id,yl=ren[i].yuan;
				if(num[idd]<nn)
				{
					ans+=ww;
					num[idd]++;
				}
				else
				{
					if(idd==1)
					{
						if(a[yl][2]>=a[yl][3])
						{
							if(num[2]<=nn)
							{
								ans+=a[yl][2];
								num[2]++;
							}
							else
							{
								ans+=a[yl][3];
								num[3]++;
							}
						}
						else
						{
							if(num[3]<=nn)
							{
								ans+=a[yl][3];
								num[3]++;
							}
							else
							{
								ans+=a[yl][2];
								num[2]++;
							}
						}
					}
					else if(idd==2)
					{
						if(a[yl][1]>=a[yl][3])
						{
							if(num[1]<=nn)
							{
								ans+=a[yl][1];
								num[1]++;
							}
							else
							{
								ans+=a[yl][3];
								num[3]++;
							}
						}
						else
						{
							if(num[3]<=nn)
							{
								ans+=a[yl][3];
								num[3]++;
							}
							else
							{
								ans+=a[yl][1];
								num[1]++;
							}
						}
					}
					else
					{
						if(a[yl][2]>=a[yl][1])
						{
							if(num[2]<=nn)
							{
								ans+=a[yl][2];
								num[2]++;
							}
							else
							{
								ans+=a[yl][1];
								num[1]++;
							}
						}
						else
						{
							if(num[1]<=nn)
							{
								ans+=a[yl][1];
								num[1]++;
							}
							else
							{
								ans+=a[yl][2];
								num[2]++;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
