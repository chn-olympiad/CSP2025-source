#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5000005];
int sum;
int he;
int mac;
void dfs(int x,int cl)
{
	if(mac>=he) return ;
	if(x>2)
	{
		sum++;
	}
	for(int i=x;i<cl;i++)
	{
		mac+=a[i];
		cout<<i<<' '; 
		dfs(x+1,cl);
	}
}
signed main()
{ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		he=a[i];
		mac=0;
		dfs(1,i);
	}
	cout<<sum%998244353;
	return 0;	
} 
