#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm;
	cin>>n>>m;
	nm=n*m;
	int r,tmp;
	cin>>r;
	int sum=1;
	for(int i=1;i<nm;i++)
	{
		cin>>tmp;
		if(tmp>r)sum++;
	}
	int a=sum/n,b=sum%n;
	if(b==0)b=n;
	else a++;
	if(a%2==1)
	{
		cout<<a<<' '<<b;
	}
	else
	{
		cout<<a<<' '<<n-b+1;
	}
	return 0;
}
