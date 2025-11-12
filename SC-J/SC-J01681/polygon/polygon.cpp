#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=5e4+5,mod=998244353;
int n;
int a[N],res;
void dfs(int x,int sum,int id,int kl){
	if(x==id){
		if(sum>kl) res++;
		res%=mod;
		return ;
	}
	if(sum>kl){
		res+=(1<<(id-x));
		res%=mod;
		return ;
	}
	dfs(x+1,sum,id,kl);
	dfs(x+1,sum+a[x],id,kl);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int k=a[i]*2;
		res=0;
		dfs(1,a[i],i,k);
//		cout<<res<<'\n';
		ans+=res;
		ans%=mod;
	} 
	cout<<ans;
	return 0;
}
/*
形式化题意
在一个序列中，对于一个集合，其元素之和大于最大元素的两倍，求个数
暴力思路
枚举每一个数作为最大值时有几个集合

*/