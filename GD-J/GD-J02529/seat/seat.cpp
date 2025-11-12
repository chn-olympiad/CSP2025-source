#include<bits/stdc++.h>
using namespace std;

int n,m,p;//p为人数 
int s[105];
int o = 1;//o为顺序 
int cnt = 1;//计数器 
int rs;//小R的分数 
int x = 1,y = 1;//x为行,y为列 

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p = n*m;
	for(int i = 1;i <= p; i++)
	{
		cin>>s[i];
	}
	rs = s[1];
	sort(s+1,s+1+p,cmp);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s[cnt] == rs)
			{
				cout<<x<<" "<<y;
				return 0;
			}
			if(y<m && o == 1)
			{
				y++;
			}
			else if(y>1 && o ==2)
			{
				y--;
			}
			else if(y == m && o == 1)
			{
				x++;
				o = 2;
			}
			else if(y == 1 && o == 2)
			{
				x++;
				o = 1;
			}
			cnt++;
		}
	}
	return 0;
}
