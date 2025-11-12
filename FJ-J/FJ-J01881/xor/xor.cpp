#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[114514*5];
int ans=0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=n;l++) 
		for(int r=l;r<=n;r++)
		{
			int sx=0;
			for(int x=l;x<=r;x++) sx^=a[x];
			if(sx==k) ans++,r++,l=r;
		}
	cout<<ans;
	return 0;
}
//rp++;

