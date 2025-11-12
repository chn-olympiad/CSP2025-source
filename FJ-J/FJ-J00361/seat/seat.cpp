#include <bits/stdc++.h>
using namespace std;

int a[50][50];

int main()
{
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	int n,m;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=m;j++)
 		{
 			cin>>a[i][j];
 		}
 	}
 	int cnt=1,num=a[1][1];
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=m;j++)
 		{
 			if(a[i][j]>num)cnt++;
 		}
 	}
 	int L,H;
	if(cnt%n==0)
	{
		L=cnt/n;
		if(L%2==1)H=n;
		else H=1;
	}
	else
	{
		L=(cnt/n)+1;
		if(L%2==1)H=cnt-(L*n)+n;
		else H=(L*n)-cnt+1;
	} 
	
	cout<<L<<" "<<H;
   	return 0;
}

