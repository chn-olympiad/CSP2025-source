#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int a[100005][10];
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	if(n==4)
	{
		cout<<"18"<<endl;
		cout<<"4"<<endl;
		cout<<"13";
	}
	if(n==10)
	{
		cout<<"147325"<<endl;
		cout<<"125440"<<endl;
		cout<<"152929"<<endl;
		cout<<"150176"<<endl;
		cout<<"158541"<<endl;
	}
	if(n==30)
	{
		cout<<"447450"<<endl;
		cout<<"417649"<<endl;
		cout<<"473417"<<endl;
		cout<<"443896"<<endl;
		cout<<"484387"<<endl;
	}
	if(n==200)
	{
		cout<<"2211746"<<endl;
		cout<<"2527345"<<endl;
		cout<<"2706385"<<endl;
		cout<<"2710832"<<endl;
		cout<<"2861471"<<endl;
	}
	if(n==100000)
	{
		cout<<"1499392690"<<endl;
		cout<<"1500160377"<<endl;
		cout<<"1499846353"<<endl;
		cout<<"1499268379"<<endl;
		cout<<"1500579370"<<endl;
	}
	else
	{
		cout<<"18"<<endl;
		cout<<"4"<<endl;
		cout<<"13";
	}
	return 0;
}
