#include<bits/stdc++.h>
using namespace std;
char s[105];
int c[105],p[105];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	int ans=0;
	do
	{
		int sum=0,out=0;
		for(int i=1;i<=n;i++)
		{
			if(out>=c[p[i]])
			{
				out++;
				continue;
			}
			if(s[i]=='1') sum++;
			else out++;
		}
		ans+=(sum>=m);
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

