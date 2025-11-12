#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,cnt;
int c[N];
string s;
long long jc[N];
void pre()
{
	jc[0]=jc[1]=1;
	for(int i=2;i<=n;i++)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
	}
}
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	pre();
	cout<<jc[n];
	return 0;
}
