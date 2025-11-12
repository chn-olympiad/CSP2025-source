#include <bits/stdc++.h>

using namespace std;

int seat[11][11] = {0},chengji[122] = {0};
int n = 0,m = 0,goal = 0,site = 0,sign1 = 0,sign2 = 0;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n*m;i++)
	{
		cin>>chengji[i];
	}
	
	goal = chengji[0];
	
	for(int i = 0;i<n*m-1;i++)
	{
	for(int j = i;j<n*m-1;j++)
	{
		if(chengji[j]<chengji[j+1])
		{
			swap(chengji[j],chengji[j+1]);
		}
	 } 
    }
    
    for(int i = 0;i<n*m;i++)
    {
    	if(chengji[i] == goal)
    	{
    		site = i+1;
    		break;
		}
	}
	
	sign1 = site/n;
	sign2 = site%n;
	if(sign2 == 0)
	{
		cout<<sign1<<' '<<m;
	}
	else
	{
		cout<<sign1+1<<' '<<sign2;
	}
	
    
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
