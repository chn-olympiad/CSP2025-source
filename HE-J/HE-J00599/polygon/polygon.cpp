#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int M=1e5+7;

int n;
int cnt;
//int sum;

int Sum(int a,int b)
{
	int res=1ll;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int logn[M];
int f[M][M];

void init()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++) logn[i]=logn[i>>1]+1ll;
	for(int i=1;(i<<1)<=m;i++)
		for(int j=i-1;(j+(1<<(i-1)))<=m;j++)
			f[i][j]=max(f[i-1ll][j],f[i-1ll][j+(1ll<<i)+1ll]);
	int l,r;
	cin>>l>>r;
	int x=logn[r-l+1ll];
	int ans=max(f[x][l],f[x][r-(1ll<<l)+1ll]);
	ans%=mod;
	int sum=Sum(2,ans);
	cout<<sum<<"\n";
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	vector<int> s(n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		cnt+=s[i];
//		if(s[i]==1) sum++;
	}
	sort(s.begin(),s.end());
//	for(int i=0;i<n;i++) cout<<s[i]<<" ";
	if(n==3)
	{
		if(cnt>2*s[2]) cout<<1;
		else cout<<0;
	}
	else
	{
		int ans=0;
		for(int i=2;i<n;i++)
		{
			int maxn=s[i];
			for(int j=0;j<i-1;j++)
				if(s[j]+s[j+1]>maxn) ans++;
		}
		if(n>=s[n-1]) cout<<((s[n-1]*2-ans+1)%mod+mod)%mod/ans;
		else cout<<((s[n-1]-ans*2)%mod+mod)%mod/ans;
	}
//	for(int i=0;i<n;i++) cout<<s[i]<<" ";
	
	return 0;
}
