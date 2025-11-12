#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],s=1,t=0,k;
string c;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			t++;
	}
	for(int i=1;i<=n-t;i++)
		s=s*i%998244353;
	cout<<s;
	return 0;
}
