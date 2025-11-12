#include<bits/stdc++.h>
using namespace std;

int n,m,ans=0;
int mod=998244353;
int a[5005],b[5005];

void dfs(int id,int k){
	b[k]=a[id];
	if(k==m){
		int maxn=0,sum=0;
		for(int i=1;i<=m;i++){
			maxn=max(maxn,b[i]);
			sum+=b[i];
			
		}
		if(maxn*2<sum){
			ans++;
		}
		return ;
	}
	if(id==n)return ;
	for(int i=id+1;i<=n;i++){
		dfs(i,k+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=0;
	}
	if(f==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans-=(1+n+((n-1)*n/2));
		cout<<ans;
		return 0;
	}
	if(n<=3){
		if(n==3&&(max(max(a[1],a[2]),a[3]))*2<(a[1]+a[2]+a[3]))cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		m=i;
		dfs(0,0);
	}
	cout<<ans;
	return 0;
}
