#include<bits/stdc++.h>
using namespace std;
int n,m[5005],l[5005],ans;
bool p(int x,int y)
{
	return x>y;
} 
void dfs(int a,int b,int c,int d)
{
	if(a>=3&&b>c*2)
	{
		ans++;
	} 
	for(int i=d;i<=n;i++)
	{
		if(l[i]==0)
		{
			l[i]=1;
			dfs(a+1,b+m[i],max(c,m[i]),i);
			l[i]=0;
		}
	}
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	sort(m+1,m+1+n,p);
	dfs(0,0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 	
}
