#include<bits/stdc++.h>
using namespace std;
int t;
int ansn[10];
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1 ; i <= t ; ++ i) 
	{
		int n;
		ansn[i] = 0;
		int ans = 0;
		int ans1 = 0;
		int ans2 = 0;
		int ans3 = 0;
		scanf("%d",&n);
		for(int j = 1 ; j <= n ; ++ j) 
		{
			int a1,a2,a3;
			scanf("%d%d%d",&a1,&a2,&a3);
			ans = max(a1 , a2);
			ans = max(ans , a3);
			int nn = n / 2;
			if(ans == a1) 
			{
				if(ans1 <= nn) 
				{
					ans1 ++;
					ansn[i] += ans;
				} 
				else 
				{
					ans = max (a2 , a3);
					if(ans == a2) 
					{
						if(ans2 <= nn)
						{
							ans2 ++;
							ansn[i] += ans;
						} 
						else 
						{
							ansn[i] += a3;
						}
					}
					else if(ans == a3) 
					{
						if(ans3 <= nn) 
						{
							ans3 ++;
							ansn[i] += ans;
						} 
						else 
						{
							ansn[i] += a2;
						}
					}
				}
			} 
			else if(ans == a2) 
			{
				if(ans2 <= nn) 
				{
					ans2 ++;
					ansn[i] += ans;
				} 
				else 
				{
					ans = max (a1 , a3);
					if(ans == a1) 
					{
						if(ans1 <= nn) 
						{
							ans1 ++;
							ansn[i] += ans;
						} 
						else 
						{
							ansn[i] += a3;
						}
					} 
					else if(ans == a3)
					{
						if(ans3 <= nn) 
						{
							ans3 ++;
							ansn[i] += ans;
						} 
						else 
						{
							ansn[i] += a1;
						}
					}
				}
			} 
			else if(ans == a3) 
			{
				if(ans3 <= nn) 
				{
					ans3 ++;
					ansn[i] += ans;
				} 
				else 
				{
					ans = max (a1 , a2);
					if(ans == a1) 
					{
						if(ans1 <= nn) 
						{
							ans1 ++;
							ansn[i] += ans;
						} 
						else 
						{
							ansn[i] += a2;
						}
					} 
					else if(ans == a2)
					{
						if(ans2 <= nn) 
						{
							ans2 ++;
							ansn[i] += ans;
						} 
						else 
						{
							ansn[i] += a1;
						}
					}
				}
			}
		}
	}
	for(int i = 1 ; i <= t ; ++ i)
	{
		printf("%d\n",ansn[i]);
	}
	return 0;
}
