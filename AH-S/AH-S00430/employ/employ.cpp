#include<bits/stdc++.h>
using namespace std;
int c[10000];
int x[10000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,flag=0;
	string s;
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]=='0') x[i+1]=0;
		else x[i+1]=1;
		if(x[i]==1) flag++;
	}
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	if(flag<m)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
