#include <iostream>
#include <algorithm>
using namespace std;
//finish！耶 。 
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,R,x,aa,bb;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(R==a[i])
		{
			x=n*m-i+1;
		}
	}
	
	if (x%n!=0)
	{
		cout<<x/n+1<<" ";
		aa=x/n+1;
	}
	else
	{
		cout<<x/n<<" ";
		aa=x/n;
	}
	if (aa%2==0)
	{
		cout<<m-x%n+1;
	}
	else
	{
		cout<<x-m*(aa-1);
	}
	
	/*
	cout<<"\n"<<x<<" "<<R;
	for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}
	*/
	return 0;
}