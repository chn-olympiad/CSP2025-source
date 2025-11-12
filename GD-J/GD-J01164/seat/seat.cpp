#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],sum;
bool cmp(int a,int b)
{
	return a>b;
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
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			sum=i;
			break;
		}
	}
	int num=(sum-1)%n+1,num1=(sum-1)/n+1;
	cout<<num1<<' '<<(num1%2==1?num:n-num+1);
	return 0;
} 
