#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,s[101],seat=1;

bool cmp(int a,int b)
{
	return a>b;
}

void sit(int R)
{
	y=1;
	for(x = 1;1;)
	{
		for(;1;)
		{
			if(seat==R){cout<<x<<" "<<y;return ;}
			if(x%2==1&&y!=n)
			{
				y++;
			}
			else if(x%2==1&&y==n)
			{
				x++;
			}
			else if(x%2==0&&y==1)
			{
				x++;
			}
			else if(x%2==0&&y!=1)
			{
				y--;
			}
			seat++;
		}
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int R = s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++)
	{
		if(s[i]==R){R=i;break;}
	}
	sit(R);
	return 0;
} 
//%%%艾伦·图灵之神%%%
//%%%冯·诺依曼之神%%%
//%%%%%%%%%%%%%%%%%%%%
//佑我此题100分 
