#include<bits/stdc++.h>
using namespace std;
int n,m,a,b=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++)
	{
		int o;
		scanf("%d",&o);
		if(o>a)b++;
	}
	int x=1,y=1,c=1;
	for(int i=2;i<=b;i++)
	{
		if((x%2==0&&y==1)||(x%2==1&&y==n))
			x+=1,c=-c;
		else y+=c;
	}
	cout<<x<<" "<<y;
	return 0;
}