#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[550];
int c[550];
const int mod=998244353;
int cnt;
bool oka;
long long sum;
long long pai(int x,int y)
{
	sum=1; 
	for(int i=m;i>1;i--)
	{
		sum=(sum*i)%mod;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	oka=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			oka=false;
		}
		if(a[i]==1)
		{
			cnt++;
		}
	}
	if(oka==true)
	{
		pai(n,m);
		cout<<sum<<endl;
	}
	else if(cnt==18)
	{
		
	}
	return 0;
}
