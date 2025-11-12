#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[101];
bool pd(int x,int y)
{
	if(y>x)
		return false;
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,pd);
	for(int i=1;i<=n*m;i++)
		if(a[i]==ans)
		{
			ans=i;
			break;
		}
	if(ans%n==0)
		if((ans/n)%2==0)
			cout<<ans/n<<" "<<1;
		else
			cout<<ans/n<<" "<<n;
	else
		if((ans/n+1)%2==1)
			cout<<ans/n+1<<" "<<ans%n;
		else
			cout<<ans/n+1<<" "<<n-ans%n+1;
	return 0;
}
