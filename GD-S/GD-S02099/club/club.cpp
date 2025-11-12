#include<iostream>
#include<vector>
using namespace std;
int n,t,x,y,a[3][4],b[6];
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		a[1][1]=max(a[2][2],a[2][3])+a[1][1];
		a[1][2]=max(a[2][1],a[2][3])+a[1][2];
		a[1][3]=max(a[2][1],a[2][2])+a[1][3];
		b[i]=max(a[1][1],max(a[1][2],a[1][3]));
	}
	for(int i=1;true;i++)
	{
		if(b[i]==0) return 0;
		else cout<<b[i]<<endl;
	}
	return 0;
} 
