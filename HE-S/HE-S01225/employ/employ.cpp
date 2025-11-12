#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[501];
string s;
bool b[501];
void dfs(int x,int step,int k)
{
	if(s[step-1]=='0'&&a[x]+1>=step) k++;
	if(step==n)
	{
		if(k==m)
			sum++;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]) continue;
		b[i]=1;
		dfs(i,step+1,k);
		b[i]=0;
	}
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		b[i]=1;
		dfs(i,1,0);
		b[i]=0;
	}
	cout<<sum;
	return 0;
}
