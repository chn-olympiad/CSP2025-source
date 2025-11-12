#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int club[100001][5];
	int d1[500001];
	int d2[500001];
	int d3[500001];
	int n,t,z,satify1,satify2,satify3,all1,all2,all3;
	cin>>t;
	cin>>n;
	for(int num=1;num<=n;num++)
	{
		club[n][1]=num;
		club[n][2]=0;
		club[n][3]=0;
		club[n][4]=0;
	}
	for(int num=1;num<=((n/2)+1);num++)
	{
		d1[num]=0;
		d2[num]=0;
		d3[num]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>satify1;
		cin>>satify2;
		cin>>satify3;
		club[i][2]=satify1;
		club[i][3]=satify2;
		club[i][4]=satify3;
	}
	for(int a=1;a<=(n-1);a++)
	{
		if(club[a][2]<club[a][3])
		{
			if(club[a][3]<club[a][4])
			{
				d3[a]=club[a][4];
			}
			else
			{
				d2[a]=club[a][3];
			}
		}
		else
		{
			if(club[a][2]<club[a][4])
			{
				d3[a]=club[a][4];
			}
			else
			{
				d1[a]=club[a][2];
			}
		}
	}
	for(int a=1;a<=n/2;a++)
	{
		all1=all1+d1[a];
	}
	for(int a=1;a<=n/2;a++)
	{
		all2=all2+d2[a];
	}
	for(int a=1;a<=n/2;a++)
	{
		all3=all3+d3[a];
	}
	cout<<all1<<endl;
	cout<<all2<<endl;
	cout<<all3<<endl;
	return 0;
}

