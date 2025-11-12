#include<bits/stdc++.h>
using namespace std;
struct o
{
	int b,c;
}a[105];
bool cmp(o l1,o l2)
{
	return l1.b>l2.b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i].b;
		a[i].c=i;
	}
	sort(a+1,a+1+x,cmp);
	int idx=0;
	for(int i=1;i<=x;i++)
	{
		if(a[i].c==1) 
		{
			idx=i;
			break;
		}
	}
	int i,j;
	i=(idx+n-1)/n;
	if(i%2==0)
	{
		j=n-(idx-n*(i-1))+1;
	}
	else
	{
		j=idx-n*(i-1);
	}
	cout<<i<<" "<<j;
	return 0;
}