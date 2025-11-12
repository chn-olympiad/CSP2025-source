#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],c[5005][5005];
int n;
int dfs(int rd,int e,int sum,int v){
	if(rd==0){
		return int(sum>2*a[e]);
	}
	int tot=0;
	for(int i=e+1;i<=n;i++){
		tot+=dfs(rd-1,i,sum+a[i],v)%mod;
		tot%=mod;
	}
	return tot;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int q=0;
	bool p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(p)q+=a[i];
		if(q>n)p=0;
	}
	sort(a+1,a+1+n);
	if(!(p&&q==n)){
		p=0;
	}
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		cout<<(2*max(max(a[0],a[1]),a[2])<a[0]+a[1]+a[2])?1:0;
	}
	else if(p){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j==0||j==i){
					c[i][j]=1;
				}
				else {
					c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
				}
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=mod;
		}
		cout<<ans;
	}
	else {
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=dfs(i,0,0,i);
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
