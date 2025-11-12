#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1],s,b[n][m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j])
			{
				int z=a[j];
				a[j]=a[i];
				a[i]=z;
			}
		}
	}
	int pp=1; 
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0){
			for(int j=1;j<=m;j++)
			{
				b[i][j]=a[pp];
				if(s==a[pp])
				{
					cout<<i<<" "<<j;
					return 0;
				}
				pp++;
			}
		}
		else{
			for(int j=1;j<=m;j++)
			{
				b[i][m-j+1]=a[pp];
				if(s==a[pp])
				{
					cout<<i<<" "<<m-j+1;
					return 0;
				}
				pp++;
			}
		}
	}
	return 0;
}
