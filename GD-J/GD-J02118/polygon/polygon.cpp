#include<bits/stdc++.h>
const int N = 5010, Mod = 998244353;
using namespace std;
int n,a[N],s[N];
long long ans;
int dfs(int now,int sum,int maxx){
	if(now==n+1){
		if(sum>maxx*2) return 1;
		return 0;
	}
	int ss=0;
	ss+=dfs(now+1,sum+a[now],a[now]);
	ss+=dfs(now+1,sum,maxx);
	return ss%Mod;
}
/*
5
1 1 1 1 1
*/
int d[N];
//int f[N*N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){ // 15 ~ 20
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--)
				(d[j]+=d[j-1])%=Mod;
			d[1]++;
		}
		for(int i=3;i<=n;i++)
			(ans+=d[i])%=Mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	if(n<=3){
		if(s[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<dfs(1,0,0);
//	if(s[3]>a[3]*2) f[s[3]]=1;
//	for(int i=4;i<=n;i++){
//		for(int j=a[i]*2+1;j<=s[i];j++){
//			f[j]+=f[j-a[i]];
//		}
//	}
//	for(int i=0;i<s[n];i++) ans+=f[i];
//	cout<<ans;
	return 0;
}

