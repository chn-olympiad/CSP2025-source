#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n;
int a[100005][5];
void dfs(int idx,int s1,int s2,int s3,int love)
{
	if (s1>n/2 || s2>n/2 || s3>n/2)
		return;
	if (idx>n)
	{
		ans=max(ans,love);
		return;
	}
	dfs(idx+1,s1+1,s2,s3,love+a[idx][1]);
	dfs(idx+1,s1,s2+1,s3,love+a[idx][2]);
	dfs(idx+1,s1,s2,s3+1,love+a[idx][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
