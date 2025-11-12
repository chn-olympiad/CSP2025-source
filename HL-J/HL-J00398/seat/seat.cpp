#include <iostream>
using namespace std;
int n,m;int a[15][15],b[105];
int main ()
	{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		 cin>>b[i];
	int x=1,y=1,r=b[1];
	for (int i=1;i<=n*m;i++)
		for (int j=1;j<n*m;j++)
			if (b[j]<b[j+1]) swap(b[j],b[j+1]);
	
//	for (int i=1;i<=n*m;i++) cout<<b[i];
	//cout<<endl;
	int flag=1;
	//cout<<r<<" "<<b[1]<<endl;
	if (b[1]==r) 
		{
		cout<<"1 1";
		return 0;
		  }  
	for (int i=2;i<=n*m;i++)
		{
		if (y==m && flag==1)
			{
			x++;flag=0;
			}
		else if(y==1 && flag==0)
			{
			x++;flag=1;
			}
		else if (flag==1) y++;
		else if (flag==0) y--;
		
		if (b[i]==r) 
			{
			cout<<x<<" "<<y;
			break;
			}
		}
	return 0;
}
