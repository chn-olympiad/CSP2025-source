#include<bits/stdc++.h>
using namespace std;
int main()
{
	feropen("seat.in","r",stdin);
	feropen("seat.out","w",stdin);
	int n,m,x;
	int A[10100];
	cin>>n>>m;
	x=n*m;
	for(int i=0;i<=x;i++)
	{
		cin>>A[i];
	}
	for(int j=4;j>=0;j--)
	{
		if(A[4]>A[j])
		{
			A[4]=A[j];
		}
	}
	A[4]=A[n+1,m+1];
	cout<<n-1<<" "<<m<<" "	;
	return 0;	
}
