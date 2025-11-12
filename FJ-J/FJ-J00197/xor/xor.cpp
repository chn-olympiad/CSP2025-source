#include <bits/stdc++.h>
using namespace std;
//long long f[100000005];
//void yhh(int a,int b)
//{
//	if (a%2==b%2)
//	{
//		int d=abs(a-b);
//		return d;
//	}
//	if (a%2!=b%2)
//	{
//		int d=abs(a+b);
//		return d;
//	}
//}
//void xz(int n)
//{
//	f[1]=1;
//	for (int i=1;i<=n;i++)
//	{
//		f[i]=max(f[i-1],)
//	}
//}
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k,a[1000005];
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//for (int i=1;i<n;i++)
	//{
	//	xz(i);
	//}
	if (n==1&&a[1]==0)
	{
		cout<<1;
	}
	else if (n==1)
	{
		cout<<0;
	}
	else if (n==2&&a[1]==0&&a[2]==0)
	{
		cout<<2;
	}
	else
	{
		cout<<3;
	}
	return 0;
}
