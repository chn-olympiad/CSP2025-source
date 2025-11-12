#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],sum,c,r,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)sum=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	if(a[i]==sum)
	{
		num=n*m-i+1;
		break;
	}
	c=num/n;
	if(num%n!=0)c+=1;
	cout<<c<<" ";
	num-=(c-1)*n;
	if(num==0)num+=n;
	if(c%2==1)cout<<num;
	if(c%2==0)cout<<n-num+1;
	return 0;
} 
