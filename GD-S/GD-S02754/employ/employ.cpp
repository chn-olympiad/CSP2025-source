#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[10001],qzj[10001],f[2][511][511],C[511][511],g[511];
char a[10001];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int cnt=0;
	qzj[0]=1;
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		qzj[i]=qzj[i-1]*i%mod;
		C[i][0]=1;
		for(int z=1;z<=i;z++)
		{
			C[i][z]=(C[i-1][z]+C[i-1][z-1])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1,w;i<=n;i++)
	{
		cin>>w;
		c[w]++;
	}
	bool ju=0;
	for(int i=1;i<=n;i++)
	{
		if(c[0]) f[0][i][1]=c[0];
		if(a[i]=='0')
		{
			ju=1;
			f[0][i][0]=1;
			break;
		}
	}
	if(!ju&&!c[0])
	{
		cout<<qzj[n];
		return 0;
	}
	int sum=c[0],ans=0;
	for(int i=0;i<n-m;i++)
	{
		sum+=c[i+1];
		int I=i&1,II=i&1^1;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				f[II][j][k]=0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int l=0;l<=c[i+1];l++)
				{
					for(int z=j+1;z<=n;z++)
					{
						(f[II][z][k+l+1]+=f[I][j][k]*C[j-k][l]%mod*qzj[l]%mod*C[c[i+1]][l]%mod*(sum-(k+l)))%=mod;
//						if(f[I][j][k]&&z==3&&k+l+1==3) cerr<<i<<" "<<j<<" "<<k<<" -> "<<i+1<<" "<<z<<" "<<k+l+1<<" : "<<C[j-k][l]%mod*qzj[l]%mod*C[c[i+1]][l]%mod*(sum-(k+l))<<"\n";
						if(a[z]=='0')
						{
							(f[II][z][k+l]+=f[I][j][k]*C[j-k][l]%mod*qzj[l]%mod*C[c[i+1]][l])%=mod;
							break;
						}
					}
				}
//				cerr<<i<<" "<<j<<" "<<k<<" : "<<f[I][j][k]<<"\n";
			}
		}
		int psum=sum-c[i+1];
		for(int j=n;j>=1;j--)
		{
			(ans+=f[I][j][psum]*C[j-psum][c[i+1]]%mod*qzj[c[i+1]]%mod*qzj[n-sum])%=mod;
//			cerr<<i<<" "<<j<<" "<<psum<<" : "<<f[I][j][psum]<<" "<<ans<<"\n";
			if(a[j]=='0') break;
		}
	}
	cout<<ans<<"\n";
}
/*
3 2
111
0 1 1
*/
/*
你有一个序列 a
然后统计多少种重拍 c 的方案数满足至少 m 位有 c_i>a_i 且 a_i=a_{i-1}
直接开始设状态吧
f_{i,j} 已经填完 a<i 和 c<i 的，其中 j 个人录用了。
转移考虑枚举 c=i+1 录用多少人，这些人要被填到前面的空位中 
这是轻松的
未被录用的人方案不好算，那我们可以假装他们都没被录用，最后乘个阶乘算至少 j 个人录用的方案数。
再来一步容斥解决问题。 
哦读错提了
f_{i,j,k} 填完 c<=i 的，恰好 i+1 个人没被录用的最早点是 j，前面填了 k 个数的方案数？
填 c=i+1 时，填在 j 前面肯定是录用的，所以随便填。
然后如果我要转移到 k，那么我需要一个数填在 k 这个位置，然后中间没有数。或者 k 一定被干掉。
直接写出来是 n^4，但是转移是区间，可以前缀和优化。  
*/
