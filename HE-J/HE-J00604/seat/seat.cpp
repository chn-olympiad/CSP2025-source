#include<bits/stdc++.h>
using  namespace std;
int a[110];
int n,m,sum=0,add=0;
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			sum=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			add=i;
			break;
		}
	}
	if(n==1||m==1)
	{
		cout<<n<<" "<<m;
		return 0;
	}
	sum=ceil(add*1.0/m);
	cout<<sum<<" ";
	if(sum%2==0)
	{
		cout<<m-add%m+1;
	}
	else
	{
		if(add%m==0)
		{
			cout<<add;
		}
		else
		{
			cout<<add%m;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
