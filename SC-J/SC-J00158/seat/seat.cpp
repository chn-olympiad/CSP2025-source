#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,h,l;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[1])
		ans++;
		}
	if(ans%n==0)
	{
		h=n;
		l=ans/n;
		}	
	else
	{
		l=ans/n+1;
		h=ans-(l-1)*n;
	}
	if(l%2==0)
	{
		h=n+1-h;
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}