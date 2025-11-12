#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int b[120],a[11][11];
int n,m,num; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int y=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				num++;
				a[j][i]=b[num];
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				num++;
				a[j][i]=b[num];
			}
		}
	}
			
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==y)
			{
				cout<<j<<" "<<i;
			}
		} 

	}
	
	return 0;
}

