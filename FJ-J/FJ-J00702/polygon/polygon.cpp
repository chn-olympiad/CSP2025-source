#include<bits/stdc++.h>
using namespace std;
int n,t=0;
int a[5001];
bool b[5001];
bool bg(int w,int v)
{
	if(w>2*v)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void ab(int x,int y)
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			y+=a[i];
			x++;
			if(bg(y,a[i])&&x>=3)
			{
				t++;
			}
			b[i]=1;
			ab(x,y);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int x=0,y=0;
	ab(0,0);
	cout<<t;
	return 0;
}
