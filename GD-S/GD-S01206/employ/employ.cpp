#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[505],c[505],xza=1,ans,ld;
long long x[505],q[505];
void dfs(int ff){//其实没卵用不理他了
 if(ff==n+1){
 	int k=0;
 	for(int i=1;i<=n;i++){
 		if(x[i]<i-k&&a[i]==1)
 			if(a[i]==1)
 				k++;
		}
		if(k>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!q[i]){
			q[i]=1,x[ff]=c[i];
			dfs(ff+1);
			q[i]=0,x[ff]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
		if(!a[i])
			xza=0;
		if(a[i])
			ld++;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(ld<m){
		cout<<0;return 0;
	}
	if(xza){
		long long ans=1;
		for(long long i=1;i<=n;i++)
			ans=ans*(i%mod)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}//20分代码(?)
//stO ��F Orz
