#include<iostream>
using namespace std;
const int N=5e5+5,M=(1<<20)+20;
bool vis[M];
int n,k,s,f[N],ans,p[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vis[0]=1;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		s^=x;
		f[i]=f[i-1];
		if(vis[k^s]==1)
			f[i]=max(p[k^s]+1,f[i]);
		ans=max(ans,f[i]);
		p[s]=max(p[s],f[i]);
		vis[s]=1;
	}
	cout<<ans;
	return 0;
}
/*
dp即可
f[i]表示1-i划分最小段数
两种情况：
1.不选i，段数为f[i-1]
2.选i，
一个段[l,i]满足条件的要求是：a[l]^a[l+1]^…^a[i]=k
前缀异或和可以将上式变成 s[l-1]^s[i]=k (s[i]=a[1]^a[2]^…^a[i]) 
再进行变形 s[l-1]=s[i]^k
所以要找 所有s[l-1]=s[i]^k 中最大的 f[l]+1 即可
由于s[i]和k都不大，最大只有2^20
所以拿一个数组p存下所有s[i]对应的f即可
那么递推式就是f[i]=max(f[i-1],p[s[i]^k]+1)
但是要注意，必须要存在 s[j]=s[i]^k 才可以使用对应的p数组
所以用一个vis维护是否存在 s[j]=s[i]^k 即可
别忘了算完f[i]后更新p数组和vis数组 
*/ 
