#include<bits/stdc++.h>
using namespace std;

int nums;
int data[5005];
int sum=0;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>nums;
	for(int i=1;i<=nums;i++)
	{
		cin>>data[i];
		sum+=data[i];
	}
	sort(data+1,data+1+nums); 
	if(data[3]*2<sum)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
} 
