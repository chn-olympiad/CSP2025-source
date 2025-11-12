#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
const int mod = 998244353;
int n,a[N],b[N];
bool vid[N];
int ans,mx=-1,sum=0,m=1;
void dfs(int idx,int len,int k)
{
	if(len==k && sum>2*mx)
	{
		ans++;
		ans%=mod;
//		for(int i=1;i<=len;i++)
//		 cout<<b[i]<<" ";
//		cout<<endl;
		return;
	}
	for(int i=a[idx];i<=n;i++)
	{
		
//		cout<<idx<<endl;
		if(vid[i]==0)
		{
			vid[i]=1;
			mx=max(a[i],mx);
//			b[i]=a[i];
			sum+=a[i];
			dfs(idx+1,len+1,k);
			vid[i]=0;
			sum-=a[i];
		}
		
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		dfs(1,0,i);
	cout<<ans%mod;
	return 0;
 } 