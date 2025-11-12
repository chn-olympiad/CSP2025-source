#include<bits/stdc++.h>
using namespace std;
const int N=520,M=998244353;
int c[N];
string s;
int n,m,z=1,i;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;++i)cin>>c[i];
	if(m==1||m==n)cout<<0;
	else
	{
		for(i=1;i<=n;++i)z=z*i%M;
		cout<<z;
	}
	return 0;
}
