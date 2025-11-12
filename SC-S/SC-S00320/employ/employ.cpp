#include<bits/stdc++.h>
using namespace std;
int n,m,c[500];
int sums;
char s[500];
long long ansss(int x)
{
	long long ans;
	for(int i=0;i<x;i++)
	{
		ans=(ans%998244353*(x-i)%998244353)%998244353;
	}
	return ans%998244353; 
}
int main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i];
		if(s[i])
		sums++;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
	}
	if(sums<m)
	{
		cout<<"0\n";
		return 0;
	}
	if(sums==n)
	{
		cout<<ansss(sums);
		return 0;
	}
	if(m==n)
	{
		cout<<"0";
	}
	return 0;
} 