#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int ans=a[1],sum=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]!=ans)
		{
			sum++;
		}
		else
		{
			break;
		}
	}
	if(sum%n==0)
	{
		int num=sum/n;
		if(num%2==0)
		{
			cout<<num<<" "<<1;
		}
		else
		{
			cout<<num<<" "<<n;
		}
	}
	else
	{
		int num=sum/n;
		sum=sum%n;
		cout<<num+1<<" ";
		if((num+1)%2==0)
		{
			cout<<n-sum+1;
		}
		else
		{
			cout<<sum;
		}
	}
	return 0;
}
