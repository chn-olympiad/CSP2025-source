#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,b[101];
bool gz(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int sum=n*m;
	cin>>b[1];
	int num=b[1];
	for(int i=2;i<=sum;i++)
		cin>>b[i];
	sort(b+1,b+sum+1,gz);
	int k=0;
	for(int i=1;i<=sum;i++)
		if(b[i]==num) {k=i;break;}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1) for(int j=1;j<=m;j++)
		{
			t++;
			if(t==k) {cout<<i<<" "<<j;return 0;}
		}
		else for(int j=m;j>=1;j--)
		{
			t++;
			if(t==k) {cout<<i<<" "<<j;return 0;}
		}
	}
}
