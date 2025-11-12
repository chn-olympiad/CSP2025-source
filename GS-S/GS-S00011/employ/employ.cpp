#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int employ_1[N];
int employ_2[N];
void employ ()
{
	int n,i,temp_1,temp_2,temp_3;
	cin>>n;
	for(int k;k<n;k++)
	{
		cin>>employ_1[k];
		cin>>employ_2[k];
	}
	for(int j;j<n;j++)
	{
		for(int c;c<j-1;c++)
		{
			if(employ_1[j]>employ_1[j+1])
			{
				temp_1=employ_1[j];
				employ_1[j]=employ_1[j+1];
				employ_1[j+1]=temp_1;
			}
			if(employ_2[j]>employ_2[j+1])
			{
				temp_2=employ_2[j];
				employ_2[j]=employ_2[j+1];
				employ_2[j+1]=employ_2;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t;
	cin>>t;
	for(int i;i<t;i++)
	{
		employ();
	}
	return 0;
}
