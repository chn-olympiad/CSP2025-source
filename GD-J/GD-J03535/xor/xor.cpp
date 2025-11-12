#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,mod=1e9+7;
int a[N],s[N];
bool f[(1<<20)+10];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	f[0]=1;
	int lp=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(f[s[i]^k])
		{
			ans++;
			for(int j=lp;j<i;j++) f[s[j]]=0;
			lp=i;
		}
		f[s[i]]=1;
	}
	cout<<ans;
	return 0;
}
/*
100pts
预估黄
8:54切了 
9:49 发现差点挂了，f 数组大小开了 10^6，连大样例都 hack 不掉
今年大样例太水了
*/
