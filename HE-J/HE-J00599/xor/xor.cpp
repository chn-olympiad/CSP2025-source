#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
const int N=5e5+7;

int n,k;
int s[N];
int f[N];
int sum=0,cnt=0;
//int f[N][25];
//int sum[25];

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s[i]=x;
		if(x==1) sum++;
		if(x==0) cnt++;
//		for(int j=0;j<=22;j++)
//		{
//			if(x&1) f[i][j]=1;
//			else f[i][j]=0;
//			x>>=1;
//		}
	}
	
	if(sum==n)
	{
		if(k==0) cout<<n/2<<"\n";
		else cout<<sum<<"\n";
		return 0;
	}
	if(sum+cnt==n)
	{
		if(k==1) cout<<sum<<"\n";
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
				if(s[i]==s[i+1]&&s[i]) ans++,i++;
			cout<<ans+cnt<<"\n";
		}
		return 0;
	}
	
	f[1]=s[1];
	for(int i=2;i<=n;i++) f[i]=f[i-1]^s[i];
//	for(int i=0;i<=22;i++)
//	{
//		if(k&1) sum[i]=1;
//		else sum[i]=0;
//		k>>=1;
//	}
	int ans=-INF;
	for(int l=1;l<=n;l++)
	{
		int sum=0,idx=l,r=l;
		while(r<=n)
		{
			int x=f[r]^f[idx-1];
			if(x==k)
			{
				sum++;
//				cout<<idx<<" "<<r<<" "<<x<<"---\n";
				idx=r+1;
				r=idx;
			}
			else r++;
		}
		ans=max(ans,sum);
//		cout<<ans<<"+++\n";
		ans+=sum;
	}
	cout<<ans<<"\n";
	
	return 0;
}
