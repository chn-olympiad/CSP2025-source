#include<iostream>
using namespace std;
int const max=100;
int main()
{
	int n,m;
	cin>>n>>m;
	int nm[n*m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>nm[i];
	}
	int e=1;
	for(int i=2;i<=n*m;i++)
	{
		if(nm[1]<nm[i])
		{
			e++;
		}
	}
	if(e==1)
	{
		cout<<"1"<<" "<<"1";
	}
	else if(e<=n)
	{
		cout<<"1"<<" "<<e;
		
	}
	else if(e==n+1)
	{
		cout<<"2"<<" "<<"1";
	}
	else if(e==2*n+1)
	{
		cout<<"3"<<" "<<"1";
	}
	else cout<<e/n+1<<e-n+1;
	return 0;
}
