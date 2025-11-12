#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100001]={},n,m,ans=0,num=0;
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--)
	{
		if(a[i]==ans)
		{
			ans=num-i+1;
			break;
		}
	}
	num=ans/n;
	if(ans%n!=0)
	{
		num++;
	}
	ans%=n;
	if(ans==0)
	{
		ans=n;
	}
	if(num%2==0)
	{
		ans=n-ans+1;
	}
	cout<<num<<" "<<ans;
	return 0;
}
