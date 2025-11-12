#include<iostream>
using namespace std;
const int MAXN=5060;
int n,arr[MAXN],ans,sum;
void dfs(int step,int maxx)
{
	if(step>=3)
	{
		if(sum>2*maxx)
		{
			ans++;
		}
	}
	for(int i=step;i<=n;i++)
	{
		sum+=arr[i];
		dfs(i+1,max(maxx,arr[i]));
		sum-=arr[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	dfs(1,arr[1]);
	cout<<ans;
	return 0;
}
