#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500005],sum[500005];//xorsum
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,pos=0,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		//cout<<sum[i]<<" ";
		if((sum[i]^sum[pos])==k)
			cnt++,pos=i;
	}
	cout<<cnt<<endl;
	return 0;
}
