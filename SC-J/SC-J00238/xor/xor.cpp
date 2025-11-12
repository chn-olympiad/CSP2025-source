#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
map<int,bool>m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	int ans=0;m[0]=true;
	for(int i=1;i<=n;i++)
	{
		if(m[a[i]^k])
		{
			m.clear();
			ans++;
		}
		m[a[i]]=true;
	}
	cout<<ans;
	return 0;
}