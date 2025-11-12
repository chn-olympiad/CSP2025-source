#include <bits/stdc++.h>
using namespace std;
int lengths[1000],l2[1000];
int number;
int give(int much,int big,int chosenplace,int nums)
{

	lengths[chosenplace]=0;
	if(much==1)
	{
		for(int i=0;i<number;i++)
		{
			if(lengths[i]==0)
			{
				continue;
			}
			if(lengths[i]>big)
			{
				nums++;
			}
		}

		return nums;
	}
	
	for(int i=0;i<number;i++)
	{
		if(lengths[i]==0)
		{
			continue;
		}
		int maxone=max(big,lengths[i]);
		int minone=min(big,lengths[i]);
		int use=maxone-minone;
		
		nums+=give(much-1,use,i,0);
	}

	return nums;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>number;

	for(int i=0;i<number;i++)
	{
		cin>>lengths[i];
		l2[i]=lengths[i];
	}
	
	int answer=0;
	for(int many=3;many<=number;many++)
	{
		for(int i=0;i<number-many+1;i++)
		{
			answer+=give(many-1,lengths[i],i,0);
			
		}
	}
	cout<<answer;
	return 0;
}
