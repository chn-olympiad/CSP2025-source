#include<bits/stdc++.h>
using namespace std;
int n,k,a[555555];
int yihuo(int a,int b)
{
	string x,y;
	for(int i=1;a>0;a/=2)
	{
		x+=(char)(48+a%2);
	}
	cout<<x<<' ';
	for(int i=1;b>0;b/=2)
	{
		y+=(char)(48+a%2);
	}
	cout<<y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	yihuo(4,8)
}
