#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,shu;
	cin>>m>>n;
	int a[m*n],b[m][n];
	cin>>a[0];
	shu=a[0];
	for(int i=1;i<m*n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m*n;i++)
	{
	for(int j=i;j<m*n;j++)
	{
		if(a[j]>=a[i])
		swap(a[i],a[j]);
	}
	}
	int x=0;
	for(int k=0;k<n;k++)
	{
	for(int j=0;j<m;j++)
	{
		if(k%2==0)
		b[j][k]=a[x];
		else
		b[m-j-1][k]=a[x];
		x++;
	}
	}
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	 {
		 if(b[i][j]==shu)
		 {
			 cout<<j+1<<" "<<i+1<<" ";
		 }
	 }
	 	 return 0;
	fclose(stdin);
	fclose(stdout);
}
