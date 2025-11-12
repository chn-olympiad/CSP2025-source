#include<bits/stdc++.h>
using namespace std;
int n,m,c;
string s;
int a[505];
void dfs(int k,int yp,int pd[])
{
	if(s[k]=='0')
	{
		dfs(k+1,yp,pd);
		return ;
	}
	if(k>=n)
	{
		if(yp>=m)
		{
			c++;
		}	
		return ; 
	}
	for(int i=0;i<n;i++)
	{
		if(k-yp<a[i]&&pd[i]==0)
		{
			pd[i]=1;
			dfs(k+1,yp+1,pd);l;
			pd[i]=0; 
		}
	}
	dfs(k+1,yp,pd);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int pd[505]={0};
	dfs(0,0,pd);
	cout<<c<<'\n'; 
	return 0;
}
