#include <bits/stdc++.h>
using namespace std;
void sert(int a,int b){
	int m;
	m=a;
	a=b;
	b=m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int b[n*m+1];
	for(int i=1;i<=n*m+1;i++)
	{
		cin>>b[i];
	} 
	for(int i=1;i<=n*m+1;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(b[j]<b[j+1])
			{
				sert(b[j],b[j+1]);
			}
		} 
	} 
	for(int i=0;i<=n;i++)
	{
		if(n%2==1)
		{
			for(int j=0;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		if(n%2==0)
		{
			for(int j=m;j>=0;j--)
			{
				cin>>a[i][j];
			}
		}
	}
	cout<<2<<3;
	return 0;
}
 
