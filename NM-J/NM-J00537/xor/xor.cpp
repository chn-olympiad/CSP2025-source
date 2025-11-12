#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0,k=0;
	cin>>n>>k;
	int a[1001]={0};
	int sort_a[1001]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sort_a[i]=a[i];
	}
	sort(sort_a,sort_a+n);
	int kp=0;//kp为k的下标(从1开始) 
	for(int i=0;i<n;i++)
	{
		if(sort_a[i]==k)
		{
			kp=i;
		}
	}
	if(sort_a[kp-1] != 0 && sort_a[kp-2] != 0)
	{
		if(sort_a[kp+1] != 0 && sort_a[kp+2] != 0)
		{
			cout<<(sort_a[kp]-sort_a[kp-1])-(sort_a[kp+1]-sort_a[kp-1]);
		}
	}
	else
	{
		sort_a[kp-2]=sort_a[kp+1]+1;
		sort(sort_a,sort_a+n);
		cout<<sort_a[kp-2]<<" "<<sort_a[kp+2];
		if(sort_a[kp+1] != 0 && sort_a[kp+2] != 0)
		{
			//cout<<(sort_a[kp+2]-sort_a[kp-1])-(sort_a[kp+1]-sort_a[kp-1]);
		}
	}
	
	return 0;
}
