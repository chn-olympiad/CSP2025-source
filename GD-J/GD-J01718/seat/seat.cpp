#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[111];
int ind;
bool aaa(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+n*m,aaa);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==a1)ind=i+1;
	}
	cout<<(ind+n-1)/n<<' ';
	if((ind+n-1)/n%2==1)
	{
		if(ind%n==0)cout<<n;
		else cout<<ind%n;
	}
	else
	{
		if(ind%n==0)cout<<1;
		else cout<<n-ind%n+1;
	}
	return 0;
}
