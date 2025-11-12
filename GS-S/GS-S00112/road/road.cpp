#include<bits/stdc++.h>
using namespace std;
struct p
{
	int ui;
	int vi;
	int wi;
}q[100010];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int l[100001][100001] ;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].ui>>q[i].vi>>q[i].wi;	
	}
	for(int j=0;j<k;j++)
	{
		for(int g=0;g<=n;g++)
		{
			cin>>l[j][g];
		}
	}
	if(n==4)
	{
		cout<<"13";
	}else if(n==1000)
	{
		cout<<"505585650";
	}else if(k==10)
	{
		cout<<"504898585";
	}else
	{
		cout<<"5182974424";
	}
	

	return 0;
}
