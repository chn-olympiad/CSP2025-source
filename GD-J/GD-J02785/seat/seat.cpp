#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];
	int cnt=a[0];
	sort(a,a+n*m);
	int p;
	for(int i=0;;)
	{
		if(cnt>a[i])
		{
			i++;
		}
		else if(cnt<a[i])
		{
			i--;
		}
		else
		{
			p=n*m-i;
			break;
		}
	}
	int lie=ceil(p/(n*1.0));
	int hang;
	if(lie%2==1)
	{
		hang=p-(lie-1)*n;
	}
	else
	{
		hang=n+1-(p-(lie-1)*n);
	}
	cout<<lie<<" "<<hang; 
	
}
