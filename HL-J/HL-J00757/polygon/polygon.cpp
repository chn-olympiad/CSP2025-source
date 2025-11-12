#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int a[5000];
int main()
{
	int op=2;
	int oq=3;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int num;
	int cnt=0;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
}
	
		for(int j1=1;j1<=num;j1++)
		{
			
			for(int j2=j1+1;j2<=num;j2++)
			{
				
				for(int j3=j2+1;j3<=num;j3++)
				{
					
					if(j3<=num){
						if(a[j1-1]+a[j2-1]+a[j3-1]>2*max(max(a[j1],a[j2]),a[j3]))
						cnt++;
						
					}
				}
				
			}
			
		}


	cout<<cnt;
	return 0;
}