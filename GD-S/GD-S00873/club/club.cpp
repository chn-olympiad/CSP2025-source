#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t,n,num1,num2,num3,ans;
int a1[N],a2[N],a3[N];
bool flag2=1,flag3=1;

void gc()
{
	cin >> t;
	while (t--)
	{
		num1=num2=num3=ans=0;
		flag2=flag3=1;
		cin >> n;
		priority_queue<pair<int,int>> xy,xz,yx,yz,zx,zy;
		for (int i = 1;i <= n;i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
			if (a2[i]!=0)flag2=0;
			if (a3[i]!=0)flag3=0;
			if (a1[i]>=a2[i]&&a1[i]>=a3[i])
			{
				num1++;ans+=a1[i];
				xy.push({a2[i]-a1[i],i});
				xz.push({a3[i]-a1[i],i});
			}
			else if (a2[i]>=a1[i]&&a2[i]>=a3[i])
			{
				num2++;ans+=a2[i];
				yx.push({a1[i]-a2[i],i});
				yz.push({a3[i]-a2[i],i});
			}
			else
			{
				num3++;ans+=a3[i];
				zx.push({a1[i]-a3[i],i});
				zy.push({a2[i]-a3[i],i});
			}
		}
		if (flag2&&flag3)
		{
			sort(a1+1,a1+n+1);
			for (int i = 1;i <= n/2;i++)
				ans-=a1[i];
			printf("%d\n",ans);
			continue;
		}
		if (num1>=num2&&num1>=num3)
		{
			while(num1>n/2)
			{
				int x = xy.top().second;
				int sumx=xy.top().first;
				int y = xz.top().second;
				int sumy=xz.top().first;
				if (sumx>sumy)
				{
					ans+=sumx;xy.pop();num2++;
					yz.push({a3[x]-a2[x],x});
				}
				else if(sumx<sumy)
				{
					ans+=sumy;xz.pop();num3++;
					zy.push({a2[y]-a3[y],y});
				}
				else 
				{
					if (num2>num3)
					{
						ans+=sumy;xz.pop();num3++;
						zy.push({a2[y]-a3[y],y});
					}
					else if(num2<num3)
					{
						ans+=sumx;xy.pop();num2++;
						yz.push({a3[x]-a2[x],x});
					}
					else
					{
						if(a3[x]-a2[x]>=a2[y]-a3[y])
						{
							ans+=sumx;xy.pop();num2++;
							yz.push({a3[x]-a2[x],x});
						}
						else
						{
							ans+=sumy;xz.pop();num3++;
							zy.push({a2[y]-a3[y],y});
						}
					}
				}
				num1--;
			}
			while (num2>n/2)
			{
				ans+=yz.top().second;
				yz.pop();
				num2--;
				num3++;
			}
			while (num3>n/2)
			{
				ans+=zy.top().second;
				zy.pop();
				num3--;
				num2++;
			}
		}
		else if (num2>=num1&&num2>=num3)
		{
			while(num2>n/2)
			{
				int x = yx.top().second;
				int sumx=yx.top().first;
				int y = yz.top().second;
				int sumy=yz.top().first;
				if (sumx>sumy)
				{
					ans+=sumx;yx.pop();num1++;
					xz.push({a3[x]-a1[x],x});
				}
				else if(sumx<sumy)
				{
					ans+=sumy;yz.pop();num3++;
					zx.push({a1[y]-a3[y],y});
				}
				else 
				{
					if (num2>num3)
					{
						ans+=sumy;yz.pop();num3++;
						zx.push({a1[y]-a3[y],y});
					}
					else if(num2<num3)
					{
						ans+=sumx;yx.pop();num1++;
						xz.push({a3[x]-a1[x],x});
					}
					else
					{
						if(a3[x]-a2[x]>=a2[y]-a3[y])
						{
							ans+=sumx;yx.pop();num1++;
							xz.push({a3[x]-a1[x],x});
						}
						else
						{
							ans+=sumy;yz.pop();num3++;
							zx.push({a1[y]-a3[y],y});
						}
					}
				}
				num2--;
			}
			while (num1>n/2)
			{
				ans+=xz.top().second;
				xz.pop();
				num1--;
				num3++;
			}
			while (num3>n/2)
			{
				ans+=zx.top().second;
				zx.pop();
				num3--;
				num1++;
			}
		}
		else
		{
			while(num3>n/2)
			{
				int x = zx.top().second;
				int sumx=zx.top().first;
				int y = zy.top().second;
				int sumy=zy.top().first;
				if (sumx>sumy)
				{
					ans+=sumx;zx.pop();num1++;
					xy.push({a2[x]-a1[x],x});
				}
				else if(sumx<sumy)
				{
					ans+=sumy;zy.pop();num2++;
					yx.push({a1[y]-a2[y],y});
				}
				else 
				{
					if (num2>num3)
					{
						ans+=sumy;zy.pop();num2++;
						yx.push({a1[y]-a2[y],y});
					}
					else if(num2<num3)
					{
						ans+=sumx;zx.pop();num1++;
						xy.push({a2[x]-a1[x],x});
					}
					else
					{
						if(a3[x]-a2[x]>=a2[y]-a3[y])
						{
							ans+=sumx;zx.pop();num1++;
							xy.push({a2[x]-a1[x],x});
						}
						else
						{
							ans+=sumy;zy.pop();num2++;
							yx.push({a1[y]-a2[y],y});
						}
					}
				}
				num3--;
			}
			while (num1>n/2)
			{
				ans+=xy.top().second;
				xy.pop();
				num1--;
				num2++;
			}
			while (num2>n/2)
			{
				ans+=yx.top().second;
				yx.pop();
				num2--;
				num1++;
			}
		}
		printf("%d\n",ans);
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	gc();
	return 0;
}
