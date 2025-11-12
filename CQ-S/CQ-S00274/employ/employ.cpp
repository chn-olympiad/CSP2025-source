#include<bits/stdc++.h>
using namespace std;
const int M=505,mod=998244353;
int n,m,a[M],c[M],vis[M],p[M],t,f;
long long ans;
string s;
void dfs(int l){
	if(l==n+1){
		int x=0,sum=0;
		for(int i=1;i<=n;i++){
			if(x>=c[p[i]])x++;
			else if(!a[i])x++;
			else sum++;
		}
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[l]=i;
			vis[i]=1;
			dfs(l+1);
			vis[i]=p[l]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=0;i<n;i++){
		if(s[i]=='0')a[i+1]=0;
		else a[i+1]=1;
		if(a[i+1]!=1)f=1;
	}
	if(n<=10){
		dfs(1);
		cout<<ans%mod;
	}
	if(!f){
		ans=1;
		for(int i=n;i;i--){
			ans=ans*i%mod;
		}
		printf("%lld\n",ans);
	}
//	if(m==1){
//		for(int i=1;i<=n;i++){
//			if(a[i]=='1'){
//				x=i;
//				for(int i=1;i<=n;i++){
//					if()
//				}
//			}
//		}
//	}
	
	return 0;
}
