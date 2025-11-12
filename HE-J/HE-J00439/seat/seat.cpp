#include<bits/stdc++.h>
using namespace std;
int hang,lie,xiaos,zong;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>hang>>lie;
	zong=hang*lie; 
	for(int i=1;i<=zong;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			xiaos=a[i];
		}
	}
	int js=1;
	sort(a+1,a+zong+1);
	for(int i=hang*lie;i>=1;i--)
	{
		if(a[i]==xiaos)
		{
			xiaos=zong-i+1;
			break;
		}
	}
	int q1,q2;
	if(xiaos%hang!=0)
	{
		q1=xiaos/hang+1; 
	}
	else
	{
		q1=xiaos/hang;
	}
	if(q1%2==0)
	{
		if(xiaos%hang==0)
		{
			q2=hang;
		}
		else
		{
			q2=hang+1-(xiaos%hang);
		}
		cout<<q1<<" "<<q2<<endl;
	}
	if(q1%2!=0)
	{
		if(xiaos%hang==0)
		{
			q2=hang;
		}
		else
		{
			q2=xiaos%hang;
		}
		cout<<q1<<" "<<q2<<endl;
	}
} 
