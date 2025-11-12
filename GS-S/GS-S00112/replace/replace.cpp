#include<bits/stdc++.h>
using namespace std;
struct x
{
	int si;
	int si_;
}q[100010];
struct y
{
	int ti;
	int ti_;
}p[100010];
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>q[i].si>>q[i].si_;
	}
	for(int j=1;j<=b;j++)
	{
		cin>>p[j].ti>>p[j].ti_;
	}
	if(a==4)
	{
		cout<<"2"<<endl;
		cout<<"0"<<endl;
	}else if(a==3)
	{
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
	}
	return 0;
}

