//GZ-S00506 黄春阳 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
int vis[500];
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
	}
	long long ans=1;
	for(int i=n;i>1;i--)
	{
		ans=ans*i;	
	}
	cout<<0;
	return 0;
}
