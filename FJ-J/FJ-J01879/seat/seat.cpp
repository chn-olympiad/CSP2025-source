#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
	return a<b;	
}
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int id=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==id) 
		{
			id=n*m-i+1;
			break;
		}
	}
	if(m==1)
	{
		cout<<id<<" "<<1;
		return 0;
	}
	cout<<n<<" "<<1;
	return 0;
}
