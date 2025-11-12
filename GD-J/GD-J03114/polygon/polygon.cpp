#include<bits/stdc++.h>
using namespace std;

int n,st[5010],ans=0;
bool dfs(int time,int sum)
{
	if(time==n)
	{
		if(sum>2*st[n]) ans++;
		return 1;
	}
	
	dfs(time+1,sum+st[time]);
	dfs(time+1,sum);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
	}
	sort(st,st+1+n);
	for(int i=1;i<=n;i++) cout<<st[i];
	//dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
