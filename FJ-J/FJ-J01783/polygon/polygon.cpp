#include<bits/stdc++.h>
using namespace std;

int a[6000];

int jiecheng(int n,int m)
{
	int s=1;
	for(int i = 0;i < m;i++)
	{
		s*=n-i;
	}
	return s;
}
long long s = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n=0;
	int num=0;
	int maxed = 0;
	int t = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	for(int i = 3;i < n;i++)
	{
		num = jiecheng(n,i)/jiecheng(i,i);
		s+=num;
	}
	cout<<s;

	return 0;
}
                            