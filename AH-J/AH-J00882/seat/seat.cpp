#include<bits/stdc++.h>
using namespace std;
int a[12][12],b[110];
int n,m,c;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>b[i];
	c=b[1];
	sort(b+1,b+1+n*m,cmp);
	int x=1,y=1,i=1;
	while(b[i]!=c)
	{
		if(x%2==0)
		{
			if(y==1)x++;
			else y--;
		}
		else if(x%2==1)
		{
			if(y==n)x++;
			else y++;
		}
		i++;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
