#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long ans=1;
string s;
int n,m,cnt,a[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
			cnt++;
	}
	for(int i=cnt;i>cnt-m;i--)
		ans=(ans*i)%MOD;
	cout<<ans;
	return 0;
}