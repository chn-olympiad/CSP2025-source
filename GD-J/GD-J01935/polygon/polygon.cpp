#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
#define ll long long
int n,a[maxn];
ll ans;
bool allone=1;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
//群山曾向神明供奉以为绝世貌美的女孩……
//但如磐石般不受肤浅者钟意……
//恒常之雨降下……
//咳咳 
//你也许也意识到了这件事……
//旅船是掩盖未来的虚像，战车指引着我们的命运……
//硬币抛出后，正反面的转换从未停止……
//前方毁灭亦是重生
//鉴定为魔怔因有人 
//O(2^n)暴力，不想想正解，但是考试结束还有1.5h
//想想吧 
void dfs(int i,int sm,int mx,int k){
	if(i>n)return;
	if(sm+a[i]>2*max(mx,a[i])&&k+1>=3){
		ans++;ans%=mod;
	}
	dfs(i+1,sm+a[i],max(mx,a[i]),k+1);
	dfs(i+1,sm,mx,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],allone&=(a[i]==1);
	if(allone){
		ans=(qpow(2,n)-1-n-n*(n-1)/2+mod)%mod;
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
	//初二，第一次考CSP
	//估分100+100+100+60=360
	//挂分区间[0,360] 
	//辛亏我检查了，我文件夹名准考证号写错了 
	return 0;
}//那彩虹如救赎般照耀我身！	 
