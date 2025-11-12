#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int v[510],t,n,m,a[510];
string s;
void hs(int q,int w)
{
	if(q==n+1)
	{
		if(n-w>=m)
			t++;
		return;
	}
	if(n-w<m)
		return;
	for(int i=1;i<=n;i++)
		if(v[i]==0)
		{
			v[i]=1;
			hs(q+1,(w>=a[i]||s[q]=='0'?w+1:w));
			v[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	hs(1,0);
	cout<<t<<'\n';
	return 0;
}

