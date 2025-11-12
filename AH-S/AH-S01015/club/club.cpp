
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+2;
int T,n;
ll a[N][5],ans;

inline void solve()
{
	cin>>n;
	ans=0;
	unordered_map<int,unordered_map<int,ll> > f[N/2];
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0 or a[i][3]!=0)
			f=false;
	}
	if(f)
	{
		ll b[N]={0};
		for(int i=1;i<=n;i++)
			b[i]=a[i][1];
		sort(b+1,b+1+n);
		for(int i=n/2+1;i<=n;i++)
			ans+=b[i];
		cout<<ans;
		return;
	}
	f[1][0][0]=a[1][1],f[0][1][0]=a[1][2],f[0][0][1]=a[1][3];
	for(int i=2;i<=n;i++)
		for(int A=min(i-1,n/2);A>=0;A--)
			for(int B=min(i-1-A,n/2);B>=0 and i-1-A-B<=n/2;B--)
			{
				int C=i-1-A-B;
				if(A<n/2)
					f[A+1][B][C]=max(f[A+1][B][C],f[A][B][C]+a[i][1]),ans=max(ans,f[A+1][B][C]);
				if(B<n/2)
					f[A][B+1][C]=max(f[A][B+1][C],f[A][B][C]+a[i][2]),ans=max(ans,f[A][B+1][C]);
				if(C<n/2)
					f[A][B][C+1]=max(f[A][B][C+1],f[A][B][C]+a[i][3]),ans=max(ans,f[A][B][C+1]);
			}
	cout<<ans<<'\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	
	while(T--)
		solve();
	
	return 0;
}
