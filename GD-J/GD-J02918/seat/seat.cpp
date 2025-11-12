#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int sum;
int sum1;
int cc(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+1+n*m,cc);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
	 	{
			c=i;
			break;	
		}
	}
	if(c%n==0)
	{
		sum=c/n;
		sum1=n;
	}
	else
	{
		sum=c/n+1;
		sum1=c%n;
	}
	if(sum%2==0)
	{
		cout<<sum<<" "<<n-sum1+1;
	}
	else
	{
		cout<<sum<<" "<<sum1; 
	}
	return 0;
} 
