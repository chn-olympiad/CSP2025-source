#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a,b,d,e,f,g,h;
struct node
{
	int x,y;
}c[N];
bool cmp(node x,node y)
{
	if(x.x>y.x)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	d=1;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>c[d].x;
			c[d].y=0;
			d++;
		}
	}
	c[1].y=1;
	d--;
	sort(c+1,c+1+d,cmp);
	/*
	for(int i=1;i<=d;i++)
	{
		cout<<c[i].x<<' ';
	}
	cout<<"\n";
	*/
	for(int i=1,j=1,k=1;i<=a && j<=b;k++)//i为列数,j为行数 
	{
		//cout<<i<<' '<<j<<" "<<c[k].x<<' '<<c[k].y<<"\n";
		
		if(c[k].y==1)
		{
			cout<<i<<' '<<j;
			return 0;
		}
		
		if(i%2==1)
		{
			j++;
			if(j>a)
			{
				j=a;
				i++;
			}
		}
		else
		{
			j--;
			if(j<1)
			{
				j=1;
				i++;
			}
		}
	}

	return 0;
}
/*
2 2
98 99 100 97
*/