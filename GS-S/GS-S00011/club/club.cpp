#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int Club_1[N];
int Club_2[N];
int Club_3[N];
void club ()
{
	int n,i,temp_1,temp_2,temp_3;
	cin>>n;
	for(int k;k<n;k++)
	{
		cin>>Club_1[k];
		cin>>Club_2[k];
		cin>>Club_3[k];
	}
	for(int j;j<n;j++)
	{
		for(int c;c<j-1;c++)
		{
			if(Club_1[j]>Club_1[j+1])
			{
				temp_1=Club_1[j];
				Club_1[j]=Club_1[j+1];
				Club_1[j+1]=temp_1;
			}
			if(Club_2[j]>Club_2[j+1])
			{
				temp_2=Club_2[j];
				Club_2[j]=Club_2[j+1];
				Club_2[j+1]=temp_2;
			}
			if(Club_3[j]>Club_3[j+1])
			{
				temp_3=Club_3[j];
				Club_3[j]=Club_3[j+1];
				Club_3[j+1]=temp_3;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i;i<t;i++)
	{
		club();
	}
	return 0;
}
