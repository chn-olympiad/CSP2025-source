#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],w,sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	w=a[1];
	sum=1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(w<a[i])
		sum++;
	}
	int b=sum%n,c;
	if(sum%n==0)
	c=sum/n;
	else
	c=sum/n+1;
	cout<<c<<" ";
	if(b==0)
	{
		cout<<n;
		return 0;
		}
	if(c%2==1)
	cout<<b;
	else
	cout<<(n-b+1);
	return 0;
}
