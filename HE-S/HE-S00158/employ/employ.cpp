#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int nx[500];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	//定义计数器
	int num=0;
	//输入数组
	for(int i=1;i<=n;i++)
	{
		cin>>nx[i];
		if(a[i]=='1')
		{
			num++;
		}
	}
	if(num==n)
	{
		cout<<0;
	 } 
	else
	{
		cout<<(n*n-num*num)%998244353;
	}
	
	return 0;
	//保存时记得解注释 
 } 
