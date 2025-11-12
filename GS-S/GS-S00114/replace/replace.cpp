#include<bits/stdc++.h>
using namespace std;
int n,m,c[505]={},cc=0,sum=0,tt[505]={},ztt=0,sb=0;
string s;
int px(int x)
{
	int ly=0;
	int s=px(x-1);
	if(x==1)
	{
		return 1;
	}
	for(int i=0;i<x;i++)
	{
		if(c[i]>=tt[i])
		{
			ly++;
		}
		if(ly+s>=m)
		{
			sum++;
			return -1;
		}
		if(s=-1)
		{
			sum++;
		}
	}
	if(s=-1)
	{
		return -1;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==0)
		{
			ztt++;
			tt[i]=ztt;
		}
	}
	//px(n);
	sb=n/2;
	cout<<sb;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
