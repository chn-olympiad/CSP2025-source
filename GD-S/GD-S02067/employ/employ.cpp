#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,s[505],c[505];
int ck1()
{
	for(int i=1;i<=n;i++)
		if(!s[i])
			return 0;
	return 1;
}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
namespace Main1{
	int ans,f[105][105][105];
	void main()
	{
		for(int j=0;j<=n;j++)
			for(int k=j;k<=n;k++)
				f[0][j][k]=1;
		for(int now=1;now<=n;now++)
			for(int i=n;i>=1;i--)
				for(int j=0;j<=i;j++)
					for(int k=j;k<=i;k++)
					{
						if(k<c[now])
							f[i][j][k]=add(f[i][j][k],f[i-1][j][k]);
						if(c[now]!=0&&c[now]>=k&&k>=1)
							f[i][j][k]=add(f[i][j][k],f[i-1][j][k-1]);
						if(c[now]==0&&j>=1&&k>=1)
							f[i][j][k]=add(f[i][j][k],f[i-1][j-1][k-1]);
					}
//		for(int i=1;i<=n;i++)
//			for(int j=0;j<=i;j++)
//				for(int k=j;k<=i;k++)
//					cout<<f[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<" DP\n"; 
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=(c[i]==0);
		for(int i=0;i<=n-m;i++)
			ans=add(ans,f[n][cnt][i]);
		cout<<ans;
	}
}
namespace Main2{
	int ans,bx[25],p[25],f[105][105][105];
	void dg(int x)
	{
		if(x>n)
		{
			int cnt=0,tot=0,tx=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt<c[p[i]]&&s[i]==1)
					tot++;
				else
					cnt++;
				if(!c[p[i]])
					tx++;
//				f[i][tx][cnt]++;
			}
			ans+=(tot>=m);
			return;
		}
		for(int i=1;i<=n;i++)
			if(!bx[i])
			{
				bx[i]=1;
				p[x]=i;
				dg(x+1);
				bx[i]=0;
			}
	}
	void main()
	{
		dg(1);
//		for(int i=1;i<=n;i++)
//			for(int j=0;j<=i;j++)
//				for(int k=j;k<=i;k++)
//					cout<<f[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<" DP\n"; 
		cout<<ans;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(ck1())Main1::main();
	else
		Main2::main();
	return 0;
}
