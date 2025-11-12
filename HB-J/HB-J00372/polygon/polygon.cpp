#include<iostream>
#include<algorithm>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a,sizeof(a));
	if(sum>maxa*2)
		cout<<1;
	else
		cout<<0;
	return 0;
}
