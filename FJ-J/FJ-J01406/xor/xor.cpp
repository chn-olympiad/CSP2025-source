#include<bits/stdc++.h>
using namespace std;
int l=1;
int n,k;
int a[500005];
int sum[500005];
long long ans=0;
int r=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=r+1;j<=i;j++)
		{
			if((sum[i]^sum[j-1])==k&&j>r)
			{
				ans++;
				r=i;
				j=r;
				//cout<<j<<" "<<i<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
