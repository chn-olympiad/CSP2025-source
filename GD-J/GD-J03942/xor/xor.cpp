#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,k[N],s[N],f[N],maxn;
map<int,int> mp; 
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i-1],s[i]=s[i-1]^k[i-1];
	mp[0]=-1;
	for(int i=1;i<=n;i++)
	{
		f[i]=maxn;
		int fin=m^s[i];
		int se=mp[fin];
		if(se==-1) f[i]=max(f[i],1ll);
		else if(se) f[i]=max(f[i],f[se]+1);
		mp[s[i]]=i;
		maxn=max(maxn,f[i]);
	}
	cout<<f[n]<<endl;
	return 0;
}//T3 ´óÔ¼ 100pts 
