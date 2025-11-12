#include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
int maxn=0;
int cnt=0;
void dfs(int dep,int ans)
{
	if(dep>n)
	{
		maxn=max(maxn,a[dep]);
		if(ans>maxn){
			cnt++;
		}
		return;
	}
	dfs(dep+1,ans);
	dfs(dep+1,ans+a[dep]); 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
