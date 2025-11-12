#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans=0,a[5005],w[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=0,sum=0,maxx=0,q=0;
		while(w[q]>1)w[q]=0,w[q+1]++,q++;
		w[0]++;
		for(int i=0;i<n;i++)if(w[i]==1)cnt++,sum+=a[i],maxx=max(maxx,a[i]);
		if(cnt>=3&&sum>(maxx*2))ans=(ans+1)%mod;
	}
	cout<<ans;
	return 0;
}
