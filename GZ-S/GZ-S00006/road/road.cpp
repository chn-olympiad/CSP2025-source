//GZ-S00006  遵义市播州区新蓝学校 仇佳艺 
#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
string s;
void dfs(int g[])
{
	for(int i=0; i<n; i++)
	{
		if(s[i]=='1' && cnt<=g[i] && cnt<m)
		{
			cnt++;
		}
	}
	if(cnt==m)
	{
		ans++;
	}
}
void dfszh(int g[],int k)
{
	int temp=g[k-1];
	for(int i=0; i<k; i++)
	{
		g[k-1]=g[k-1-i];
		g[k-1-i]=temp;
		dfs(g);
		dfszh(g,k-1);
		
	}
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int g[n];
	for(int i=0; i<n; i++)
	{
		cin>>g[i];
	}
	dfszh(g,n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

