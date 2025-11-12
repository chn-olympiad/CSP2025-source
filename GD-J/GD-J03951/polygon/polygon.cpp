#include<bits/stdc++.h>
#define N 5005
#define p 11
#define int long long
using namespace std;
int n,a[N],ans,b[N],bj,c;
map<int,int>w;
void dfs(int x,int sl,int h,int maxx)
{
	if(x>n) return;
	if(sl>=3&&h>maxx*2)
	{
		int t=0;
		for(int i=1;i<=n;i++)
			if(b[i]==1) t*=p,t+=i;
		w[t]++;
		if(w[t]==1) ans++;
	}
	b[x+1]=1;
	dfs(x+1,sl+1,h+a[x+1],max(maxx,a[x+1]));
	b[x+1]=0;
	dfs(x+1,sl,h,maxx);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
