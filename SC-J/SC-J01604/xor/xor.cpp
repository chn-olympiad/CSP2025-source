#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
map<int,int> pos;
int n,k,a[maxn],f[maxn],lstr,ans;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=0;
	for(int i=1;i<=n;i++)
	{
		t^=a[i];
		f[i]=t;
		int x=f[i]^k;
		if(lstr==0&&x==0)ans++,lstr=i;
		else if(pos[x]!=0&&pos[x]+1>lstr)ans++,lstr=i;
		pos[t]=i;
	}
	cout<<ans;
	return 0;
}
