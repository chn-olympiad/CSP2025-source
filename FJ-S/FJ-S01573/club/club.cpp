#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,x,y,z,a1,a2,a3;
void dfs(int aa,int bb,int cc)
{
	int no=max(aa,max(bb,cc));
	if(no==aa)
	{
		if(x+1<=n/2)
		{
			x++;
			a1+=no;
			return;
		}
		else
		{
			dfs(0,bb,cc);
		}
	}
	if(no==bb)
	{
		if(y+1<=n/2)
		{
			y++;
			a2+=no;
			return;
		}
		else
		{
			dfs(aa,0,cc);
		}
	}
	if(no==cc)
	{
		if(z+1<=n/2)
		{
			z++;
			a3+=no;
			return;
		}
		else
		{
			dfs(aa,bb,0);
		}
	}
	return;
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		x=0,y=0,z=0,a1=0,a2=0,a3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			dfs(a,b,c);
		}
		cout<<a1+a2+a3<<endl;
	}
	return 0;
}

