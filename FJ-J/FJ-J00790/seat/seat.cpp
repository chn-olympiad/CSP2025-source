#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,r;
struct node
{
	int c;
	bool r;
}a[N];
bool cmp(node a,node b)
{
	return a.c>b.c;
}
int main()
{
freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].r=true;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].c;
	}
	int h=1;
	sort(a+1,a+n*m+1,cmp);
	bool p=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i*j].r==true)
			{
				h=i*j;
				p=true;
				break;
			}
		}
		if(p==true)
		{
			break;
		}
	}
	if(h%n!=0)
	{
		cout<<h/n+1<<' ';
		if((h/n+1)%2==1)
		{
			cout<<(h/n*m)-h+1;
		}
		else
		{
			cout<<h-(h/n*m)+1;
		}
	}
	else
	{
		cout<<h/n<<' ';
		if((h/n+1)%2==1)
		{
			cout<<(h/n*m)-h+1;
		}
		else
		{
			cout<<h-(h/n*m)+1;
		}
	}
} 
