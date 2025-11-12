#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	int me=a[0];
	sort(a,a+n*m);
	int x=1,y=1,z=1;
	for(int i=n*m-1;i>=0;i--)
	{
		if(a[i]==me)
		{
			cout<<x<<' '<<y;
			break;
		}
		y+=z;
		if(y==1&&x!=1)
		{
			z=1;
			x++;
			i--;
		}
		if(y==n)
		{
			z=-1;
			x++;
			i--;
		}
		if(a[i]==me)
		{
			cout<<x<<' '<<y;
			break; 
		}
		
		if(i<0) break;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
