#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int num[10005];
int n,m,x,y,target;
bool down=true;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sizee=n*m;
	for(int i=0;i<sizee;i++) 
	{
		cin>>num[i];
		if(i==0)
			target=num[i];
	}
	sort(num,num+sizee,cmp);
	for(int i=0;i<sizee;i++)
	{
		if(num[i]==target)
			break;
		if(down)
		{
			if(x==n-1)
			{
				y++;
				down=false;
			}
			else
				x++;
		}
		else
		{
			if(x==0)
			{
				y++;
				down=true;
			}
			else
				x--;
		}
	}
	cout<<y+1<<' '<<x+1;
	return 0;
}
