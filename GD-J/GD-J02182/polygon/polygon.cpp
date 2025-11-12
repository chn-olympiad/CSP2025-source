#include<bits/stdc++.h>
using namespace std;
const long long maxx=998244353;
int n;
int a[5010];
long long q[5010],pl[5010],num,cnt;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
		if(q[i]>a[i]*2)
		{
			pl[cnt++]=i;
		}
	}
	for(int i=0;i<cnt;i++)
	{
		long long p=pl[i];
		num=q[p-1];
		long long f[num+10]={};
		f[0]=1;
		for(long long j=1;j<p;j++)
		{
			for(long long k=num;k>=a[j];k--)
			{
				f[k]+=f[k-a[j]];
			}
		}
		for(long long j=a[p]+1;j<=num;j++)
		{
			ans+=f[j];
			ans%=maxx;
		}
	}
	cout<<ans;
	return 0;
}
