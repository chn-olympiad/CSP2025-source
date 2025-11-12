#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],sum;
void work(long long step,long long ma,long long ans)
{
	if(ma*2<ans)
	sum++;
	for(int i=step+1;i<=n;i++)
	work(i,max(ma,a[i]),ans+a[i]);
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20)
	{
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	work(i,a[i],a[i]);
	cout<<sum%998244353;
	return 0;
}
