#include <iostream>
using namespace std;
long long n,a[5050],sum=0;
bool b[5050];
void dfs(long long k,long long f,long long cnt)
{
	long long maxn=-1;
	for (int i=1;i<=n;i++)if (b[i]==1)/*cout<<a[i]<<' ',*/maxn=max(maxn,a[i]);
	if (f>=3&&maxn*2<cnt)/*cout<<"true",*/sum++;
	//cout<<endl; 
	if (sum>=998244353)sum-=998244353;
	for (int i=k+1;i<=n;i++)
	{
		if (b[i]==0)
		{
			b[i]=1;
			dfs(i,f+1,cnt+a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0);
	cout<<sum<<endl;
	return 0;
}
