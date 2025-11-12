#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int Mod=998244353;
int n;
int a[N];
int Mx;
int f[N];
int g[N];
inline void add(int &x,int y)
{
	int res=x+y;
	x=(res>=Mod?res-Mod:res);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		Mx=max(Mx,a[i]);
	} 
	sort(a+1,a+1+n);
	f[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=Mx*2+1;j++)
			add(g[min(Mx*2+1,j+a[i])],f[j]);
		for(int j=a[i]*2+1;j<=Mx*2+1;j++) add(ans,g[j]);
		for(int j=0;j<=Mx*2+1;j++) add(f[j],g[j]),g[j]=0;
	}
	printf("%d",ans);
}
