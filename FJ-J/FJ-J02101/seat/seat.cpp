#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int t=n*m;
	int js=1;
	for(int i = 0 ; i < t ; i++)
	{
		cin >>a[i];
		if(a[i]>a[0])js++;
	}
	int x=1,y=1;
	int b=1;
	int ret=0;
	while(t--)
	{
		if(y==1&&t+1!=m*n)
		{
			x++;
			b=1;
			ret++;	

		}
		else if(y==n)
		{
			x++;
			b=-1;
			ret++;
		}	
		
		
		if(ret==js-1)
		{
			cout << x<<" "<<y<<endl;
		}
		y+=b;
		ret++;
		if(ret==js-1)
		{
			cout << x<<" "<<y<<endl;
		}
		
	}
	return 0;
}



