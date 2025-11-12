#include<bits/stdc++.h>
using namespace std;
#define N 500010
int n,m;
int z[N],sum[N],f[N],f1[N];
int ans,now;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>z[i];
	memset(f1,-1,sizeof f1);
	for(int i=1;i<=n;i++)
	{
		now^=z[i];
		if(f1[now^m]!=-1) f[i]=max(f[i],f1[now^m]+1);
		f[i]=max(f[i],f[i-1]),f1[now]=max(f[i],f1[now]);
	}
//		int now=0;
//		for(int j=i;j>=1;j--)
//		{
//			now^=z[j];
//			if(now==m)
//				f[i]=max(f[i],f[j-1]+1);
//		}
//		f[i]=max(f[i],f[i-1]); 
	cout<<f[n];
} 
