#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],x,ans,c[10000005],d[10000005];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j<i;j++)
		{
			if((b[i]^b[j])==k)
			{
				x=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		if(c[b[i]^k]==1&&d[b[i]^k]>=x||x==0&&b[i]==k)
		{
			x=i;
			ans++;
		}
		c[b[i]]=1;
		d[b[i]]=i;
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=(a[i]^b[i-1]);
	}
	if(n<=1000) solve1();
	else solve2();
	return 0;
}
