#include<bits/stdc++.h>
using namespace std;
int x[100][100];
int a,b,c=0,d=-1,e,f,g=0;
int y[10000];
int cmp(int z,int w)
{
	if(z>w)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a*b;i++)
	{
		cin>>y[i];
	}
	f=y[0];
	sort(y,y+(a*b),cmp);
	for(int i=1;i<=a;i++)
	{
		if(g==1)
		{
			break;
		}
		d=0-d;
		for(int j=1;j<=b;j++)
		{
			if(d==1)
			{
				e=j;
			}
			else
			{
				e=a-j+1;
			}
			if(f==y[c])
			{
				cout<<i<<" "<<e;
				g=1;
				break;
			}
			c=c+1;
		}
	}
	return 0;
}
