#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
bool b[1000000];
long long total=0;
void dfs(int sitcks,int maxn,int t)
{
	if(sitcks>maxn*2) total++;
	for(int i=t+1;i<=n;i++)
	{
		sitcks+=a[i];
		maxn=max(maxn,a[i]);
		dfs(sitcks,maxn,i);
		maxn=min(maxn,a[i]);
		sitcks-=a[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(0,0,0);
	cout<<total;
	return 0;
}
