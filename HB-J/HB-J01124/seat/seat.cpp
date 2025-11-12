#include<bits/stdc++.h>
using namespace std;
bool cp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int g[1000];
	cin>>n>>m;
	int stu=n*m;
	for(int i=0;i<stu;i++)	
	{
		cin>>g[i];
	}
	int a=g[0];
	sort(g,g+stu,cp);
	int pm=0;
	for(int i=0;i<stu;i++)	
	{
		if(g[i]==a)
		{
			pm=i+1;
			break;
		}
	}
	int lie=pm/n;
	int x=pm%n;
	if(x!=0)
	{
		lie+=1;
		if(lie%2==0)
		{
			cout<<lie<<" "<<n-x+1;
		}
		else
		{
			cout<<lie<<" "<<x;
		}
	}
	if(x==0)
	{
		if(lie%2==0)
		{
			cout<<lie<<" "<<"1";
		}
		else
		{
			cout<<lie<<" "<<n;
		}
	}
	return 0;
}
