#include<bits/stdc++.h>
#define int long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=500020;
int n,k;
int a[N];
int f[N];
map<int,int> t;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	fo(i,1,n)scanf("%lld",&a[i]),a[i]^=a[i-1];
	t[a[0]]=1;
	int ans=0;
	fo(i,1,n)
	{
		if(t.count(a[i]^k))
		{
			int x=t[a[i]^k]-1;
			f[i]=f[x]+1;
		}
		f[i]=max(f[i],f[i-1]);
		t[a[i]]=i+1;
		ans=max(ans,f[i]);
	}
//	fo(i,1,n)cout<<a[i]<<" ";cout<<endl;
//	fo(i,1,n)cout<<f[i]<<" ";cout<<endl;
	cout<<ans;
	return 0;
}
