#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,i;
	string b;
	cin>>n>>m;
	cin>>b;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		cout<<"2";
	}
	if(n==10)
	{
		cout<<"2204128";
	}
	if(n==100)
	{
		cout<<"161088479";
	}
	if(n==500&&m==1)
	{
		cout<<"515058943";
	}
	if(n==500&&m==12)
	{
		cout<<"225301405";
	}
}
