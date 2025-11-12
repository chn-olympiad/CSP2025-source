#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int mem[5005],maxn[5005];
bool b = true;

void dfs(int cur,int sum,int maxx)
{
//	cout<<"check"<<endl;
	if(cur - 1 == n)
	{
		if(sum > maxx*2)ans++;
//		cout<<sum<<' '<<maxx<<endl;
		return ;
	}
	
//	if(mem[cur] >= sum && maxn[cur] >= maxx)return;
//	mem[cur] = max(mem[cur],sum);
//	maxn[cur] = max(maxn[cur],maxx);	
	dfs(cur+1,sum,maxx);
	
	if(a[cur] > maxx)maxx = a[cur];
	dfs(cur+1,sum+a[cur],maxx);

	
}


int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i] != 1) b=false;
		mem[i] = -1;
	}
//	
	if(b)
	{
		long long sum=0;
		for(int i=3;i<n-1;i++)
		{
			long long cnt=1;
			for(int j=1;j<=i;j++)
			{
				cnt*=n-j+1;
				cnt/=j;
			}
			sum+=cnt;
		}
		cout<<sum+1+n;
		return 0;
	}
	
	dfs(1,0,0);
	
	cout<<ans;
	return 0;
}
