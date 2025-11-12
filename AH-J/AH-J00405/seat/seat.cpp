#include<bits/stdc++.h>
using namespace std;
int n,m,a[124],r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i&&a[i]>a[0])
		{
			r++;
		}
	}
	int x=1,y=1,f=1;
	for(int i=0;i<r;i++)
	{
		if(f==1&&y<m)
		{
			y++;
			continue;
		}
		if(f==1&&y==m)
		{
			f=0;
			x++;
			continue;
		}
		if(f==0&&y>1)
		{
			y--;
			continue;
		}
		if(f==0&&y==1)
		{
			f=1;
			x++;
			continue;
		}
		
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
