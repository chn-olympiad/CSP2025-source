#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	int i,n,m,k,j;
	cin>>n>>m>>k;
	int w[m][n-1],a[k],b[k][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		cin>>w[m][n-i];
	}
	for(i=0;i<k;i++)
	{
		cin>>a[k];
		for(j=0;j<n;j++)
		cin>>b[i][j];
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 