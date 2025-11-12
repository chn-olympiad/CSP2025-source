#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((sum[j]^sum[i-1])==k){b[i]=j;break;}
			}
		}
		int ji=0,ans=0;
		for(int i=1;i<=n;i++){
			if(!b[i]) continue;
			if(!ji){ji=i,ans++;continue;}
			if(b[ji]>b[i]) ji=i;
			else if(b[ji]<i) ans++,ji=i;
		}
		return cout<<ans,0;
	}
	int ji=0,ans=0;
	for(int i=1;i<=n;i++){
		if(b[ji]<i)
		{
			for(int j=i;j<=n;j++) if((sum[j]^sum[i-1])==k){b[i]=j;break;}
			if(b[i]) ji=i,ans++;
			continue;
		}
		for(int j=i;j<b[ji];j++) if((sum[j]^sum[i-1])==k){b[i]=j;break;}
		if(b[i]) ji=i;
	}
	return cout<<ans,0;
}
