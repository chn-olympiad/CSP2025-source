#include<bits/stdc++.h>
using namespace std;
struct node
{
	int fen;
	int number;
	int x;
	int y;
}  a[1005];
int n,m;
int u,v=1,l=1;
bool cmp(node xx,node yy)
{
	return xx.fen>yy.fen;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i].fen;
		a[i].number=i;
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		if(l%2==1)
		{
			u++;
			a[i].x=v;
			a[i].y=u;
			if(u==n)
			{
				v++;
				l++;
			}
		}
		else
		{
			
			a[i].x=v;
			a[i].y=u;
			
			if(u==1)
			{
				v++;
				l++;
			}
			u--;
		}
	}
	for(int i=1;i<=t;i++) 
	{	
		if(a[i].number==1)
		{
			cout<<a[i].x<<" "<<a[i].y;
			return 0;
		}
		
	}
	return 0;
} 
