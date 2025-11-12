#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;const long long MIG23=998244353;long long n,k,a[N],sum,ans;
bool used[N];
//bool check()
//{
//	long long mxx=0,all=0,ct=0;
//	for(long long i=0;i<n;i++)
//	{
//		if(used[i])
//		{
//			mxx=max(mxx,a[i]);
//			all+=a[i];
//			ct++;
//		}
//	}
//	if(ct>=3&&all>2*mxx)
//		return 1;
//	return 0;
//}
void dfs(long long cs,long long ct,long long all,long long mxx)
{
	
//	for(long long i=0;i<n;i++)
//	{
//cout<<used[i]<<" ";
//	}
//	cout<<"\n";
	if(cs>=(n))
	{
			if(ct>=3&&all>2*mxx)
			{
				sum++;
				sum=sum%MIG23;
			}
		return;
	}	
	used[cs]=0;
	dfs(cs+1,ct,all,mxx);
	used[cs]=1;
	dfs(cs+1,ct+1,all+a[cs],max(mxx,a[cs]));
	return;
}
int main()
{
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	scanf("%lld",&n);
 	for(long long i=0;i<n;i++)
 	{
 	scanf("%lld",&a[i]);
	}
	dfs(0,0,0,0);
	printf("%lld",sum);
	return 0;
}
