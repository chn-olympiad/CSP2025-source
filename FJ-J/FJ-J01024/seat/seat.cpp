#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[105]={};
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+m*n,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==x)
		{
			if(ceil(i*1.00/n)==1) cout<<1<<" "<<i;
			else if((int)ceil(i*1.00/n)%2==1) cout<<ceil(i*1.00/n)<<" "<<i%n;
			else cout<<ceil(i*1.00/n)<<" "<<m-i%n+1;
			break;
		}
	}
	return 0;
}
