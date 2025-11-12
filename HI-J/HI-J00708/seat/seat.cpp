#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],i,j,p,pm;
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	for(i=1;i<=n*m;i++)
	{
		for(j=i;j<=n*m;j++)
		{
			if(a[j]>a[i])
			swap(a[i],a[j]);
		}
	}
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==p) pm=i;
	}
	for(i=1;i<=m;i++)
	{
		if(i*m<pm)
		{
			continue;
		}
		else
		{
			cout<<i<<" "<<pm-((i-1)*n);
			break;
		}
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
