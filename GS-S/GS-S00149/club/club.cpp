#include <bits/stdc++.h>

using namespace std;

int t,n;

struct Node
{
	int a,b,c;
}d[100005];

int e,f,g,h,s,k,gg = 0,kk;

void Dfs()
{
	if(f>k||g>k||h>k)
	{
		return ;
	}
	if(s>n)
	{
		return ;
	}
	for(int i = 1;i<=3;i++)
	{
		int ss = e;
		if(i = 1)
		{
			f++;
			e += d[s].a;
			s++;
			kk = gg;
			Dfs();
			if(f>k)
			{
				gg = kk;
			}
			else
			{
				gg = max(gg,e);
			}
			f--;
			s--;
			e -= d[s].a;
			
		}
			if(i = 2)
			{
				g++;
				e+=d[s].b;
				s++;
				kk  = gg;
				
				Dfs();
							if(g>k)
			{
				gg = kk;
			}
			else
			{
				gg = max(gg,e);
			}
				s--;
				g--;
				e -= d[s].b;
				
			}
			if(i = 3)
			{
				h++;
				e+=d[s].c;
				s++;
				kk  = gg;
				Dfs();
							if(h>k)
			{
				gg = kk;
			}
			else
			{
				gg = max(gg,e);
			}
				s--;
				h--;
				e -= d[s].c;
				
			}
		}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin >> d[i].a>>d[i].b>>d[i].c;
		}
		e = 0,f = 0,g = 0,h = 0,s = 1,gg = 0;
		k = n/2;
		Dfs();
		cout<<gg<<endl;
	}
	return 0;
}
