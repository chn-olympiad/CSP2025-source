#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int N=5e3+42;
int a[N],b[N],dp[N],ans;
int vis,m;
void dfs(int cur,int maxx,int sum)
{
	if(cur>m)
	{
		if(sum>=2*maxx)ans++;
		return;
	}
	dfs(cur+1,maxx,sum);dfs(cur+1,max(maxx,a[cur]),sum+a[cur]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		m=i;dfs(1,0,0);
	}
	cout<<ans;
	return 0;

}
 
