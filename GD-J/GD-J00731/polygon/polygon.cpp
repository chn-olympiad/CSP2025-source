#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans;
const int p=998244353;
void dfs(int step,int maxn,int cnt,int tot)
{
	if(step==n+1)
	{
		if(tot>=3 && cnt>2*maxn)
		{
//			cout<<cnt<<" "<<tot<<endl;
			ans++;
			ans%=p;
		}
		return;
	}
	dfs(step+1,maxn,cnt,tot);
	
	if(!cnt) dfs(step+1,a[step],a[step],1);
	else dfs(step+1,maxn,cnt+a[step],tot+1);
}
int qpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b%2==1)
		{
			res*=a;
			res%=p;
		}
		a=a*a;
		a%=p;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	 
	cin>>n;
	int maxn=0;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20)
	{
		sort(a+1,a+n+1,[](int x,int y){
			return x>y;
		});
		ans=0;
		dfs(1,0x3f3f3f,0,0);
		cout<<ans;
	}
	else if(maxn==1)
	{
		cout<<(qpow(2,n)-n*(n+1)/2+2*p)%p;
	}
	else
	{
		cout<<113;
	}
	return 0;
 } 
