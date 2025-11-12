#include<iostream>
#include<iostream>
using namespace std;
int main()
{
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,a1,a,m=1,o=1,lx=1,ly=1;
	cin>>x>>y>>a1;
	for(int i=2;i<=x*y;i++)
	{
		cin>>a;
		if(a>a1)m++;
	}
	for(int i=1;i<=x*y-1;i++)
	{
		if(lx>x)
		{
			lx=x;
			ly+=1;
			o=0;
		}
		if(lx<1)
		{
			lx=1;
			ly+=1;
			o=1;
		}
		if(m==1)
		{
			cout<<ly<<' '<<lx;
			break;
		}
		m--;
		if(o)lx++;
		else lx--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
