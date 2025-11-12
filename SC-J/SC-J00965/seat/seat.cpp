#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[105],num;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	num=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			int t1=0;
			if(i%m!=0)
			{
				t1=1;
			}
			int h=i/m+t1;
			cout<<h<<" ";
			if(h%2==0)
			{
				cout<<i-i%m;
			}
			else
			{
				cout<<(i-1)%m+1;
			}
			return 0;
		}
	}
	return 0;
 } 