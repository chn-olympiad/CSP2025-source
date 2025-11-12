#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,m,b,x,y,z,j,max=0,a;
	cin>>j;
	cin>>i;
	char d[3]={1,2,3},n[i];
	for(i=1+i;i=n[i];i++)
	{
		a=n[i]*d[j];
		a+=a;
		if(n[i]/3<=n[i]/2)
			max=a;
	}
	max++;
	cout<<'3'<<endl;	
	cout<<i+1<<endl;
	cout<<max<<endl;
	return 0;
 } 
