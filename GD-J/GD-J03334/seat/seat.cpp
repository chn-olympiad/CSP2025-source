#include<bits/stdc++.h>
using namespace std;
const int N=15,M=15;
int a[N*M];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[1]) 
		{
			k+=1;
		}
	}
	int h,l;
	h=(k-1)/n;
	h+=1;
	l=k%n;
	if(h%2==1)
	{
		if(l==0) l=n;
		cout<<h<<" "<<l;
	}
	else
	{
		if(l==0) l=1;
		else l=n-l+1;
		cout<<h<<" "<<l;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
