#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010],b[10010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=0;
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
			k++;
	}
	k+=1;
	int l=ceil(k*1.0/n);
	cout<<l<<" ";
	if(l%2==0)
		cout<<m-k%n;
	else
	{
		if(k%n==0)
			cout<<n;
		else
			cout<<k%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 