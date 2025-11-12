#include<iostream>
#include<algorithm>
using namespace std;
int n,m;//n行，m列 
int a[1005];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int he=n*m;
	for(int i=1;i<=he;i++)
	{
		cin>>a[i];
	}
	
	int meb=a[1];
	int pri;
	sort(a+1,a+he+1);
	for(int i=1;i<=he;i++)
	{
		if(a[i]==meb)
		{
			pri=he-i+1;
			break;
		}
	}
	int jo;
	int lie;int yu;
	if(pri%n==0)
	{
		lie=pri/n;
		jo=(pri/n)%2;
		yu=n;
	}
	else if(pri%n!=0)
	{
		lie=pri/n+1; 
		jo=(pri/n+1)%2;
		yu=pri-(lie-1)*n; 
	}
	
	
	if(jo==0)
	{
		cout<<lie<<" "<<n-yu+1;
	
	}
	else{
		cout<<lie<<" "<<yu;
	}
	return 0;
}