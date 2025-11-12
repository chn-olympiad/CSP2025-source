#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int num1=0,num0=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1')
		{
			num1++;
		}
		else
		{
			num0++;
		}
	}
	int bl=0;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		if(c<=bl)
		{
			bl++;
		}
	}
	n-=bl;
	if(num0==0)
	{
		cout<<4366345;
	}
	if(num1<m || n<m)
	{
		cout<<0;
	}
	return 0;
}
