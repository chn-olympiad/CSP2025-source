#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1005];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first>y.first;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int k;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].second==1) k=i;
	}
	double test=k*1.0/n;
	int x=k/n;
	if(abs(test-x)>1e-8) x++;
	int y=k%n;
	if(x%2==0)
	{
		if(y==0) y=1;
		else y=n-y+1;
	}
	else
	{
		if(y==0) y=n;
	}
	cout<<x<<" "<<y;
	return 0;
}
