#include<bits/stdc++.h>
using namespace std;
#define ll long long
	const int mod=998244353;
	int n,a[5005],f[30],s1,f1=1,p[5003][5003];
void dfs(int k,int cnt,int mx,int sum){
	if(k>n){
		if(cnt>=3&&sum>mx*2){
			s1++;
			s1%=mod;
		}
		return;
	}
	dfs(k+1,cnt,mx,sum);
	if(!f[k]){
		f[k]=1;
		dfs(k+1,cnt+1,max(mx,a[k]),sum+a[k]);
		f[k]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=0;
	}
	if(f1){
		p[3][1]=1;
		for(int i=4;i<=n;i++){
			p[i][1]=1;
			for(int j=2;j<=n-2;j++){
				p[i][j]=p[i-1][j-1]*i/(j-1);
			}
		}
		ll ans=0;
		for(int i=1;i<=n-2;i++){
			ans+=p[n][i];ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<s1;
		return 0;
	}
	
	
	return 0; 
}
