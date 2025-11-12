#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N];
long long ans,M=998244353;
void dfs(int num,int pos,int sum,int maxn)
{
	if(pos>=n)return ;
	if(num+1>=3&&pos<n)
	{
		if((sum+a[pos+1])>2*(max(maxn,a[pos+1])))
		{
//			cout<<num+1<<" "<<pos<<" "<<pos+1<<" "<<(sum+a[pos+1])<<" "<<max(maxn,a[pos+1])<<"\n";
			ans=(ans+1)%M;
		}
	}
	dfs(num+1,pos+1,sum+a[pos+1],max(maxn,a[pos+1]));
	dfs(num,pos+1,sum,maxn);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,1,a[1],a[1]);
	dfs(0,1,0,0);
	cout<<(ans%M);
	return 0;
}
