#include<bits/stdc++.h>
using namespace std;

int ans=0;
	int n,q;
	string aa[3][200005];
	
void dfs(string x,int j,int l)
{
	string y;
	for(int i=j;i<=j+l;i++)
	{
		y=y+x[j];
	}
	int fl=0;
	for(int i=1;i<=2;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(aa[i][k]==y)
			{
				fl=1;
			}
		}
	}
	if(fl)
	{
		ans++;
	}
	return ;
 } 

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);


	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		aa[1][i]=x;
		aa[2][i]=y;

	}
	for(int i=0;i<q;i++)
	{
		string x,y;
		cin>>x>>y; 
		ans=0;
		for(int i=1;i<=x.size();i++)
		{
			for(int l=1;l<=x.size()-i;l++)
			{
				dfs(x,l,i);
			}
		}
		for(int i=1;i<=x.size();i++)
		{
			for(int l=1;l<=x.size()-i;l++)
			{
				dfs(y,l,i);
			}
		}
		cout<<ans;
	 } 
	return 0;
 } 
