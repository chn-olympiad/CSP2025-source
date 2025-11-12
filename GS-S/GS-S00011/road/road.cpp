#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int road_1[N];
int road_2[N];
int road_3[N];
void road ()
{
	int n,i,temp_1,temp_2,temp_3;
	cin>>n;
	for(int k;k<n;k++)
	{
		cin>>road_1[k];
		cin>>road_2[k];
		cin>>road_3[k];
	}
	for(int j;j<n;j++)
	{
		for(int c;c<j-1;c++)
		{
			if(road_1[j]>road_1[j+1])
			{
				temp_1=road_1[j];
				road_1[j]=road_1[j+1];
				road_1[j+1]=temp_1;
			}
			if(road_2[j]>road_2[j+1])
			{
				temp_2=road_2[j];
				road_2[j]=road_2[j+1];
				road_2[j+1]=temp_2;
			}
			if(road_3[j]>road_3[j+1])
			{
				temp_3=road_3[j];
				road_3[j]=road_3[j+1];

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
		road();
	}
	return 0;
}
