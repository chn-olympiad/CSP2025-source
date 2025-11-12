#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int a[100010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,maa=-1e6-10;
	cin>>s;
	int t=s;
	int n;
	while(s)
	{
		n++;
		s/=10;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=t%10;
		t/=10;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
