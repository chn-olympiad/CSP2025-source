#include<bits\stdc++.h>
#include<iostream>
using namespace std;
int a[100][100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,y,s=0,e,f;
	  for(int i=0;i<m;i++)
	 {
	 	for(int j=0;j<n;j++)
	 	{
	 		if(a[i][j]<y&&(i!=m-1&&j!=n-1))
			{
				s++;
			}
			
		}
	}
	if((s/2)%2==0) 
	{
		e=s/2+1;
		f=n-((s/2)%2);
	} 
	else
	{
		e=s/2+1;
		f=(s/2)%2;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}