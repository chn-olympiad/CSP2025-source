#include <bits/stdc++.h>
using namespace std;
const int EE=998244353;
const int MAXN=2e5+3;
int c[MAXN];
int n,m;
long long ans=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	int ans=1;
	for(int i=m;i<=n;i++) ans*=i,ans%=EE;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
