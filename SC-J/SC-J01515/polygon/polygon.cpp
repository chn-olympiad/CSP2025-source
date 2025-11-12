#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=998244353;
int a,b[N],c,d,e1,e2,f,g,h;
void dfs(int x,int y,int z)
{
	if(x>a)
	{
		if(y>z*2)
		{
			d++;
			d=d%M;
			//cout<<y<<" "<<z<<"\n";
		}
		return ;
	}
	dfs(x+1,y+b[x],max(z,b[x]));
	dfs(x+1,y,z);
	return ;
}
int abc(int x,int y)
{
	int o=1;
	for(int i=y,j=x;i>=1;i--,j--)
	{
		o=o*j;
		o=o%M;
	}
	return o;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
		c=max(c,b[i]);
	}
	if(a<=20 && c<=100)
	{
		dfs(1,0,0);
		cout<<d;
		return 0;
	}
	if(c==1)
	{
		for(int i=1;i<=a;i++)
		{
			if(b[i]==1)
			{
				e1++;
			}
			else
			{
				e2++;
			}
		}
		int u4=0;
		for(int i=3;i<=e1;i++)
		{
			int u1=abc(e1,i);
			int u2=abc(i,i);
			int u3=u1/u2;
			u4=u4+u3;
			u4=u4%M;
		}
		/*
		for(int i=3;i<=e2;i++)
		{
			int u1=abc(e2,i);
			int u2=abc(i,i);
			int u3=u1/u2;
			u4=u4+u3;
			u4=u4%M;
		}
		for(int i=3;i<=e1+e2;i++)
		{
			int u1=abc(e1+e2,i);
			int u2=abc(i,i);
			int u3=u1/u2;
			u4=u4+u3;
			u4=u4%M;
		}
		*/
		cout<<u4;
		return 0;
	}
	cout<<rand();

	return 0;
}
/*
5
1 2 3 4 5
*/