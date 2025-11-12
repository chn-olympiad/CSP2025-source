#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,ans,anss;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int z=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int num;
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==z)
		{
			num=i;
			break;
		}
	}
	if(num%n!=0) ans=num/n+1;
	else ans=num/n;
	if(ans%2!=0) 
	{
		if(num%n==0) anss=n;
		else anss=num%n;
	}
	else
	{
		if(num%n==0)anss=1;
		else anss=n-num%n+1;
	}
	cout<<ans<<" "<<anss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
