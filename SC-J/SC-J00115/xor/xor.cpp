#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int pre[N];
int dp[N];
map<int,int> change;
set<int> s[N]; 
int tot=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i];
		if(!change.count(pre[i])) change[pre[i]]=++tot;
		int tmp=change[pre[i]];
		s[tmp].insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		int tmp=pre[i-1]^k;
		if(!change.count(tmp)) continue;
		int pos=change[tmp];
		set<int>::iterator it=s[pos].lower_bound(i);
		if(it==s[pos].end()) continue;
		//cout<<i<<' '<<*it<<endl;
		dp[*it]=max(dp[*it],dp[i-1]+1);
	}
	int maxx=0;
	for(int i=1;i<=n;i++) maxx=max(maxx,dp[i]);
	printf("%d",maxx);
	return 0;
}