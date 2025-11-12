#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define N 5010
#define mod 998244353
int n;
int a[N];
int ans=0;
void dfs(int sw,int d,int sum,int mx,int ii){
	if(d==sw){
		if(mx*2<sum)ans=(ans+1)%mod;
		return;
	}
	for(int i=ii+1;i<=n;i++){
		dfs(sw,d+1,sum+a[i],max(mx,a[i]),i);
	}
}
bool flag=1;
int jc[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),flag=(a[i]==1?flag:0);
	if(n==3){
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++)sum+=a[i],maxn=max(maxn,a[i]);
		if(maxn*2<sum)cout<<1;
		else cout<<0;
	}
	else if(flag){
		jc[0]=1;
		for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
//		for(int i=1;i<=n;i++)cout<<jc[i]<<" ";
//		cout<<endl;
		for(int i=3;i<=n;i++){
			ans+=(jc[n]/jc[n-i]/jc[i]+mod)%mod;
//			cout<<jc[n]/jc[i]<<endl;
		}
		cout<<ans;
	}
	else{
		for(int i=3;i<=n;i++){
			dfs(i,0,0,0,0);
		}
		cout<<ans;
	}
	return 0;
}

