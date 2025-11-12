#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const ll N=5005,V=5000,mod=998244353;
ll n,a[N],ans,f[N][N],f2[N][N],cnt[N],sum,al,nl,s[N];
void solvemj(){
	for(int i=1;i<(1<<n);i++){
		ll maxn=0,cnt=0;
		for(int j=0;j<n;j++) 
		if((i>>j)&1) cnt+=a[j+1],maxn=max(maxn,a[j+1]); 
		if(cnt>2*maxn) ans++;
	}
	cout<<ans;
} 
void solvedp(){
	cnt[0]=1;
	for(int i=1;i<=n;i++)
	for(int j=i;j;j--) cnt[j]+=cnt[j-1], cnt[j]%=mod;
	for(int i=3;i<=n;i++) al+=cnt[i];
	//总状态 
	f[0][0]=f2[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=i;j;j--)
	for(int k=sum;k>=a[i];k--){
		f[j][k]=(f[j][k]+f[j-1][k-a[i]])%mod;
		if(k<=2*a[i]) 
		f2[j][k]=(f2[j][k]+f[j-1][k-a[i]])%mod;
	}
	for(int i=3;i<=n;i++)
	for(int j=1;j<=sum;j++) nl+=f2[i][j],nl%=mod;
	ans=((al-nl)%mod+mod)%mod; 
	cout<<ans;
	//O(n*n*n*n) -> O(n*n)?
	//能否直接 计算出 不合法状态数量？ 
	//考虑 计算 对于每一个以a[i]为最大值的组合，有多少种是不合法的
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i]; 
	sort(a+1,a+n+1);
	//子集枚举 40pts  
	if(n<=22) solvemj();
	else solvedp();
	return 0;
}
