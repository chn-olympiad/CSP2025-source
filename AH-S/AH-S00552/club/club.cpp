#include<bits/stdc++.h>
using namespace std;
int j(int x)
{
	int num,i,q,j=3,h=0;
	num=x;
	int p=num/2;
	int a[num+1][j+1];
	for(i=1;i<=num;i++)
	{
		for(q=1;q<=j;q++)
		{
			cin>>a[i][q];
		}
	}
	int a1=0,a2=0,a3=0,max=0,i1=0,q1=0;
	for(int s=1;s<=num;s++)
	{
		max=0;
		q1=0;i1=0;
	for(q=1;q<=j;q++)
	{
		for(i=1;i<=num;i++)
		{
			if(a[i][q]>=max)
			{
				max=a[i][q];
				q1=q;
				i1=i;
			}
		}
	}
	cout<<max<<endl;
	h+=max;
	for(q=1;q<=j;q++)
	{
		a[i1][q]=-1;
	}
	if(q1=1)
	{
		a1++;
	}
	if(q1=2)
	{
		a2++;
	}
	if(q1=3)
	{
		a3++;
	}
	if(a1==p)
	{
		for(i=1;i<=num;i++)
		{
			a[i][1]=-1;
		}
	}
	if(a2==p)
	{
		for(i=1;i<=num;i++)
		{
			a[i][2]=-1;
		}
	}
	if(a3==p)
	{
		for(i=1;i<=num;i++)
		{
			a[i][3]=-1;
		}
	}
}
for(i=1;i<=num;i++)
	{
		for(q=1;q<=j;q++)
		{
			cout<<a[i][q]<<" ";
		}
		cout<<endl;
	}
	return h;
}
int main()
{
	int c;
	cin>>c;
	int w[c+1],o;
	for(o=1;o<=c;o++)
	{
		cin>>w[o];
	}
	for(o=1;o<=c;o++)
	{
		cout<<j(w[o])<<endl;
	}
	return 0;
}
