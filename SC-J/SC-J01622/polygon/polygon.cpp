#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int n;
int a[5010];
int b[5010];
int c[5010];
int g[10010];
int f[10010];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int mx=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[a[i]]++;
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	int ans=0;
	g[0]=1;
	for(int j=1;j<=n;j++){
		for(int i=mx*2;i>=1;i--){
			if(a[j]>i)continue;
//			if(i==3)cout<<j<<' '<<a[j]<<' '<<i-a[j]<<' '<<g[i-a[j]]<<endl;
			g[i]=(g[i]+g[i-a[j]])%mod;
//			cout<<g[2]<<endl;
		}
	}
//	cout<<g[1]<<' '<<g[2]<<' '<<g[3]<<' '<<g[4]<<' '<<g[5]<<' '<<g[6]<<endl;
	sort(a+1,a+n+1);
//	ans=(ans+(n-tot))%mod;
//	cout<<tot<<endl;
	for(int i=1;i<=mx*2;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>i||a[j]*2<i)continue;
//			cout<<i-a[j]<<endl;
//			cout<<i<<' '<<a[j]<<' '<<g[i-a[j]]<<endl;
			ans=(ans+g[i-a[j]])%mod;
			if(a[j]*2==i)ans=(ans-1+mod)%mod;
		}
	}
	int tot=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=tot;i++){
		ans=(ans-(c[a[i]]*(c[a[i]]-1)/2)%mod+mod)%mod;
	}
	ans=(ans+mod)%mod;
//	cout<<ans<<endl;
	cout<<(ksm(2,n)-1-ans+mod)%mod<<'\n';
	
	return 0;
}
/*
T4 三个多小时？？？ 
-----
很可能是 dp 或者 图论建模 
f[i] 表示 1-i 中选择方案 
有问题。 
能不能这样，先求出能够让长度之和大于两倍的？ 
不好做 
但是 dp 现在最好的就是 f[i][j] 表示到了 i，总和为 j 的了 
n*sum*max(n^2 max^2) 的，这样有 80 分 
等等 11-14 不行，500*2000*100，4s，尝试巴雷特模乘 
但是有问题，因为没有办法判断当前是否成立 
只能再开一维，滚动数组 
还要减去 2 的情况？好像不用 
首先空间复杂度的瓶颈在于 sum，也就是 max*n， 
先写出来看看 

5
1 2 3 4 5

5 12 5
4 7 4

5
2 2 3 8 10

5
1 1 2 2 3

9

-----
开始想正解 
首先，我们不能表示总和这个状态 
所以正解真的是 dp 吗，T3 是 dp，这道题部分分也能用 dp 
怎么优化 总和？ 
主要是没有了这一维，就没有办法判断答案合不合理了 
有一种是枚举每一个答案，然后枚举是否有能对它做贡献的 a 
需要保证 a[i]*2<ans[i]，f[i] = f[i] + f[i-a[i]] 
但是 5000^3 会被卡 
怎么优化？f[i-a[i]] 
等等，这好像是诈骗题。 
因为答案和 a 完全不同阶 
可以暴力求出 <mx*2+1 的，然后其余所有都可以被所有 a 做贡献 
那会不会是矩阵快速幂？ 
很可能！！！ 
[i-mx i-mx+1 ... i-1 i]
[0 1 0 0 1... 0 0 0 1 ]
但是矩阵过大也不行 
[i-mx i-mx+1 ... i-1 i] *-
                         
应该是正解 
不对，感觉有问题 
因为 f[i] = f[i] + f[i-a[i]] 有可能 f[i-a[i]] 没有值 
f**k
继续想，即求：一堆 a[i] 能凑出的大于 mx*2 的数量 
当然是 2^n 
直接减去不符合的就行了 


完了，暴力太慢了，是 n mx^2 的 

只能优化暴力了 
先求出每种数的凑法，然后再 f[i]=f[i]+f[i-a[i]] 
注意会有两个 a[i] 的情况会重复算 
还有重复很难算 

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int n;
int a[5010];
int f[2][50010][110];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int mx=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		sum+=a[i];
	}
//	cout<<sum<<endl;
	int ans=0;
	int s=0,xx=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
		xx=max(xx,a[i]);
		for(int j=1;j<=min(s,50000ll);j++){
			for(int k=1;k<=xx;k++){
//				if(j==7&&k==3)cout<<f[(i-1)&1][j][k]<<endl;
				f[i&1][j][k]=(f[(i-1)&1][j][k])%mod;
			}
		}
		f[i&1][a[i]][a[i]]++;
		f[i&1][a[i]][a[i]]%=mod;
//		cout<<i<<' '<<f[i&1][7][3]<<'\n';
		for(int j=a[i];j<=min(s,50000ll);j++){
			int k=a[i];
			for(int t=1;t<=a[i];t++){
				f[i&1][j][k]=(f[i&1][j][k]+f[(i-1)&1][j-a[i]][t])%mod;
//				if(i==3&&j==7&&k==3){
//					cout<<f[i&1][j][k]<<' '<<f[(i-1)&1][j-a[i]][t]<<' '<<i-1<<' '<<j-a[i]<<' '<<t<<'\n';
//				}
			}
			for(k=a[i]+1;k<=mx;k++){
				f[i&1][j][k]=(f[i&1][j][k]+f[(i-1)&1][j-a[i]][k])%mod;
			} 
		}
		
	}
	for(int j=1;j<=min(s,50000ll);j++){
		for(int k=1;k<=mx&&k*2<j;k++){
//			cout<<n<<' '<<j<<' '<<k<<' '<<f[n&1][j][k]<<'\n';
			ans=(ans+f[n&1][j][k])%mod;
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}

T4 三个多小时？？？ 
-----
很可能是 dp 或者 图论建模 
f[i] 表示 1-i 中选择方案 
有问题。 
能不能这样，先求出能够让长度之和大于两倍的？ 
不好做 
但是 dp 现在最好的就是 f[i][j] 表示到了 i，总和为 j 的了 
n*sum*max(n^2 max^2) 的，这样有 80 分 
等等 11-14 不行，500*2000*100，4s，尝试巴雷特模乘 
但是有问题，因为没有办法判断当前是否成立 
只能再开一维，滚动数组 
还要减去 2 的情况？好像不用 
首先空间复杂度的瓶颈在于 sum，也就是 max*n， 
先写出来看看 

5
1 2 3 4 5

5 12 5
4 7 4

5
2 2 3 8 10

-----
开始想正解 

*/