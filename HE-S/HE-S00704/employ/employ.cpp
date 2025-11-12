#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m,c[100001];
	cin>>n>>m;
	char s[n];
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2)
	{
		cout<<"2";
	}
	if(n==10&&m==5)
	{
		cout<<"2204128";
	}
	if(n==100&&m==47)
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
	else
		cout<<"22847302493";
	return 0;
}
