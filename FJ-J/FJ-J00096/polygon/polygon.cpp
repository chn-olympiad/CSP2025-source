#include<bits/stdc++.h>
using namespace std;

const long long N=1e4+10,mod=998244353;
int n;
int a[N];
long long ans=0;
bool vis[N];

bool pd(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}

void dfs(int k,int s,int t,int num){
	if(k>s){
		if(num>t) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(k+1,s,t,num+a[i]);
			vis[i]=false;
		}
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}else if(pd()){
		for(int i=3;i<=n;i++){
			long long a=1,b=1;
			for(int j=2;j<=n;j++){
				a=a*j%mod;
			}
			for(int j=2;j<=i;j++){
				b=b*j%mod;
			}
			for(int j=2;j<=n-i;j++){
				b=b*j%mod;
			}
			ans+=(a/b)%mod;
		}
		cout<<ans%mod;
	}else{
		for(int i=3;i<=n;i++){
			for(int j=i;j<=n;j++){
				memset(vis,0,sizeof(vis));
				dfs(1,i-1,a[j],0);
			}
		}
		cout<<ans;
	}
	return 0;
}
