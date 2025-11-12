#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,a[5005];
bool b[5005];
int maxx=0x80000000;
#define mod 998244353
void dfs(int x,long long sum)
{
	if(sum>maxx*2 and x>=3)
	{
		ans++;
	//	cout<<endl;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			maxx=max(a[i],maxx);
			dfs(x+1,sum+a[i]);
			b[i]=0;
			maxx=0x80000000; 
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
//	if(n==3)
//	{
//		int A,B,C;
//		cin>>A>>B>>C;
//		int maxx=max(A,max(B,C));
//		if(A+B+C>maxx*2)
//		cout<<1;
//		else cout<<0;
//		exit(0);
//	} 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0);
	cout<<floor(ans/6/n)%mod;
}//CCF is great(too diffcult!!!)

