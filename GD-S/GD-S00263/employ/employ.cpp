#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
using namespace std;
bool f[514];int c[514];
int a[514];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
	{
		a[i]=i;
		char c;
		cin>>c;
		f[i]=c-'0';
	}
	rep(i,1,n) cin>>c[i];
	int ans=0;
	do
	{
		int cnt=0;
		rep(i,1,n)
		{
			if(f[i]==0 or cnt>=c[a[i]]) cnt++;
		}
		if(n-cnt>=m) ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
