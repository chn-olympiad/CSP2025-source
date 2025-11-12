#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x=1,y=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int num=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;a[i]!=num;i++)
	{
		if(y%2==1)
		{	
			if(x==n)	
			y++;
			else x++;
		}
		else {		
			if(x==1)
			y++;
			else x--;
		}
	}
	cout<<y<<" "<<x<<endl;
	return 0;
 }

