#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,k,ans=0;
void dfs(int idx,int s,int x)
{
	if (idx>n)
	{
		ans=max(ans,s);
		return;
	}
	int m=x^a[idx];
	if (m==k) dfs(idx+1,s+1,0);
	else 
	{
		dfs(idx+1,s,m);
		dfs(idx+1,s,0);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int c=0,f=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==0)
			c++;
		if (f==1)
			f++;
		if (a[i]!=a[i-1] || f==2) f=0;
		else if (a[i]==a[i-1] && f==0)
			c++,f=1;
	}
	if (k==0)
	{
		cout<<c;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
