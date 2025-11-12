#include <bits/stdc++.h>
using namespace std;
int minn(int x,int y, int z)
{
	return min(z,min(x,y));
}
struct iny
{
    int a,b,c;
};
int second(int a,int b,int c)
{
	int d[4] = {0,a,b,c};
	sort(d + 1, d + 4);
	return d[2];
}
bool cmp(iny a,iny b)
{
	if( max(max(a.a,a.b),a.c) > max(max(b.a,b.b),b.c) )
	{
		return 1;
	}
	else if(max(max(a.a,a.b),a.c) == max(max(b.a,b.b),b.c))
	{
		if(second(a.a,a.b,a.c) > second(a.a,a.b,a.c))
		{
			return 1;
		}
		else if(second(a.a,a.b,a.c) == second(a.b,a.b,a.c))
		{
			if(minn(a.a,a.b,a.c) > second(b.a,b.b,b.c))
			{
				return 1;
			}
		}
	}
	return 0;
}
int t;
iny a[100007];
int aa[100007][4];
iny tr[100007];
int cnt;
int n;
int ina,inb,inc;
int in[4];
long long ans = 0,total;
void up(int x)
{
	if(x == 1) return ;
	if(cmp(tr[x],tr[x/2]))
	{
		swap(tr[x],tr[x/2]);
		up(x / 2);
	}
}

void down(int x)
{
	if(x * 2 > cnt) return ;
	if(!cmp(tr[x],tr[x * 2]))
	{
		swap(tr[x],tr[x * 2]);
		down(x * 2);
	}
	else if(x * 2 + 1 < cnt and !cmp(tr[x],tr[x * 2 + 1]))
	{
		swap(tr[x],tr[x * 2 + 1]);
		down(x * 2 + 1);
	}
}
void build(iny x)
{
	tr[++cnt] = x;
	up(cnt);
}

iny top()
{
//	printf("tr[1] = %d cnt = %d \n",tr[1],cnt);
	iny x = tr[1];
	swap(tr[cnt],tr[1]);
	cnt--;
	down(1);
	return x;
}
int ma(iny a)
{
	if(a.a > a.b and a.a > a.c) return 1;
	if(a.b > a.a and a.b > a.c) return 2;
	if(a.c > a.a and a.c > a.b) return 3;
	if(a.a == a.b and a.a == a.c) return 4;
	if(a.a == a.b) return 5;
	if(a.a == a.c) return 6;
	if(a.b == a.c) return 7;
}
void dfs(int x)
{
	total = max(ans,total);
	if(x > n) return ;
	for(int i = 1; i <= 3; i++)
	{
		if(in[i] < n / 2)
		{
			in[i] ++;
			ans += aa[x][i];
			dfs(x + 1);
			in[i] --;
			ans -= aa[x][i];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
		cnt = 0;
    	ans = ina = inb = inc = 0;
        scanf("%d",&n);
        if(n == 2)
        {
        	int a, b, c, x, y ,z;
        	scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
        	if(max(max(a,b),c) - second(a,b,c) < max(max(x,y),z) - second(x,y,z))
        	{
        		printf("%d\n",second(a,b,c) + max(max(x,y),z));
			}
			else
			{
				printf("%d\n",max(max(a,b),c) + second(x,y,z));
			}
		}
		else if(n <= 10)
		{
			ans = 0;
			total = 0;
			for(int j = 1; j <= n; j++)
			{
				scanf("%d%d%d",&aa[j][1],&aa[j][2],&aa[j][3]);
			}
			dfs(1);
			printf("%lld\n",total);
		}
		else
		{
	        for(int j = 1; j <= n; j++)
	        {
	            scanf("%d%d%d",&a[j].a,&a[j].b,&a[j].c);
	            build(a[j]);
	        }
	        int x = 1;
	        while(cnt > 0)
	        {
	        	a[x++] = top();
			}
			for(int j = 1; j <= n; j++)
			{
				int xxx = ma(a[j]);
				if(xxx == 1)
				{
					ina++;
					ans += a[j].a;
				}
				if(xxx == 2)
				{
					inb++;
					ans += a[j].b;
				}
				if(xxx == 3)
				{
					inc++;
					ans += a[j].c;
				}
				if(xxx == 4)
				{
					if(ina <= inb and ina <= inc)
					{
						ina++;
						ans+=a[j].a;
					}
					else if(inb <= ina and inb <= inc)
					{
						inb++;
						ans+=a[j].b;
					}
					else
					{
						inc++;
						ans+=a[j].c;
					}
				}
				if(xxx == 5)
				{
					if(ina <= inb)
					{
						ina++;
						ans+=a[j].a;
					}
					else
					{
						inb++;
						ans+=a[j].b;
					}
				}
				if(xxx == 6)
				{
					if(ina <= inc)
					{
						ina++;
						ans+=a[j].a;
					}
					else
					{
						inc++;
						ans+=a[j].c;
					}
				}
				if(xxx == 7)
				{
					if(inb <= inc)
					{
						inb++;
						ans+=a[j].b;
					}
					else
					{
						inc++;
						ans+=a[j].c;
					}
				}
				if(ina == n / 2)
				{
					cnt = 0;
					for(int k = j + 1; k <= n; k++)
					{
						a[k].a = 0;
	//					printf("k = %d \n",k);
						build(a[k]);
					}
					x = j + 1;
					while(cnt > 0)
					{
						a[x] = top();
						x++;
	//					printf("3");
					}
				}
				if(inb == n / 2)
				{
					cnt = 0;
					for(int k = j + 1; k <= n; k++)
					{
						a[k].b = 0;
						build(a[k]);
					}
					x = j + 1;
					while(cnt > 0)
					{
						a[x] = top();
						x++;
	//					printf("2");
					}
				}
				if(inc == n / 2)
				{
					cnt = 0;
					for(int k = j + 1; k <= n; k++)
					{
						a[k].c = 0;
						build(a[k]);
					}
					x = j + 1;
					while(cnt > 0)
					{
						a[x] = top();
						x++;
	//					printf("1");
					}
				}	
			}
			printf("%lld\n",ans);
			
		}
    }

    return 0;
}
