#include<bits/stdc++.h>
using namespace std;
int t,n,tt,c1,c2,c3;//c为数量 s为下标 
struct o{
	int a;
	int b;
	int c;
	int maxn;
	int maxt; 
}u[100005];
bool cnp(o x,o y)
{
	return x.maxn > y.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j = 0;j < t;j ++)
	{
		tt = 0;
		n = 0;
		cin>>n;
		for(int i = 0;i < n;i ++)
		{
			cin>>u[i].a>>u[i].b>>u[i].c;
			if(u[i].a > u[i].b)		//找最小备选差 
				if(u[i].a > u[i].c)
				{
					u[i].maxn = u[i].a - max(u[i].b,u[i].c);
					u[i].maxt = 1;
				}		
			else
				if(u[i].b > u[i].c)
				{
					u[i].maxn = u[i].b - max(u[i].a,u[i].c);
					u[i].maxt = 2;
				}
				else
				{
					u[i].maxn = u[i].c - max(u[i].b,u[i].a);
					u[i].maxt = 3;
				}
		}
		sort(u,u + n,cnp);
		
		for(int i = 0;i < n;i ++)
		{
			if(u[i].maxt == 1 && c1 + 1 <= n / 2 || c3 + 1 > n / 2 && u[i].b < u[i].a)
			{
				tt += u[i].a;
				c1 ++;
				continue;
			}
			if(u[i].maxt == 2 && c2 + 1 <= n / 2 || c1 + 1 > n / 2 && u[i].b >= u[i].c || c3 + 1 > n / 2 && u[i].b >= u[i].a)
			{
				tt += u[i].b;
				c2 ++;
				continue;
			}	
				tt += u[i].c;
				c3 ++;
		}
		cout<<tt<<endl;
		for(int i = 0;i < n;i ++)
			u[i].a = u[i].b = u[i].c = u[i].maxn = u[i].maxt = 0;
		c1 = c2 = c3 = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
