#include<bits/stdc++.h.>
using namespace std;
int n;
long long int ans;
long long int MODN=998244353;
long long int lb[5010],slb[5010];
void pd(int r,int n,long long int s)
{
	for(int i=r;i>=max(n,1);i--)
	{
		if(slb[i]<=s)    return;
		if(lb[1]>s)
		{
			ans=int((ans+pow(2,i)-1))%MODN;
			return;
		}
		if(n<=1&&lb[i]>s)    ans=(ans+1)%MODN;
		pd(i-1,n-1,s-lb[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>lb[i];
	}
	sort(lb+1,lb+n+1);
	for(int i=1;i<=n;i++)    slb[i]=slb[i-1]+lb[i];
	for(int i=3;i<=n;i++)    pd(i-1,2,lb[i]);
	cout<<ans;
	return 0;
} 