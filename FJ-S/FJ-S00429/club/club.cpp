#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
const int N=1e5+5;
int T,n,a[N][3],val[N],p[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(;T--;)
	{
		n=read();
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++) a[i][j]=read();
		int ans=0;
		for(int w=0;w<3;w++)
		{
			int res=0;
			for(int i=1;i<=n;i++) res+=a[i][w];
			for(int i=1;i<=n;i++) p[i]=i,val[i]=max(a[i][(w+1)%3]-a[i][w],a[i][(w+2)%3]-a[i][w]);
			sort(p+1,p+n+1,[&](int x,int y)
			{
				return val[x]>val[y];
			});
			int num1=0,num2=0;
			for(int i=1;i<=n/2;i++)
			{
				res+=val[p[i]];
				if(a[p[i]][(w+1)%3]>a[p[i]][(w+2)%3]) num1++;
				else num2++;
			}
			ans=max(ans,res);
			for(int i=n/2+1;i<=n;i++)
			{
				res+=val[p[i]];
				if(a[p[i]][(w+1)%3]>a[p[i]][(w+2)%3]) num1++;
				else num2++;
				if(num1>n/2||num2>n/2) break;
				ans=max(ans,res);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
