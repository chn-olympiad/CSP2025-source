#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],num,seat;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++)
	{
		if(a[i]==num)
		{
			seat=i;
		}
	} 
	cout<<(seat+n-1)/n<<" ";
	if(seat%(2*n)<=n)
	{
		cout<<seat%(2*n);
	 } 
	else
	{
		cout<<2*n-seat+1;
	}
	return 0;
}