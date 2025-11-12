#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,s[5020],maxs,c[5200][5200];
long long ans;


void dg(int sum,int x,int m,int maxn){
	if(m>=3&&sum>2*maxn)ans++;
	for(int i=x;i<=n;i++){
		dg(sum+s[i],i+1,m+1,max(maxn,s[i]));
	}
	return;
}


int main(){
	
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		maxs=max(maxs,s[i]);
	}
	c[1][1]=1;c[1][0]=1;
	
	
	
	if(maxs==1){
		for(int i=2;i<=n;i++){
			for(int j=0;j<=i+1;j++){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
		}
		for(int j=0;j<=(n-1)/2;j++){
//			cout<<c[n][j]<<'\n';
			ans+=c[n][j];
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	
	dg(0,1,0,0);
	cout<<ans%mod;
	
	
	
	return 0;
}

