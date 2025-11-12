#include<bits/stdc++.h>
using namespace std;
int n,k;
int a,sum,f[500100];
int pre[1500000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum^=a;
		if(sum==k) f[i]=1;
		if(pre[sum^k]) f[i]=max(f[i],f[pre[sum^k]]+1);
		f[i]=max(f[i],f[i-1]);
		pre[sum]=i;
	}
	cout<<f[n]<<"\n";
}