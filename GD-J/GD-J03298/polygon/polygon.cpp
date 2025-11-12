#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],b[N],ans;
long long c[N][N];
bool dfs(int now,int lenn,int nowlen,int maxa,int i,long long sum){
	if(now>=i){
		return false;
	}
	if(nowlen==lenn){
		if(sum>maxa){
			return true;
		}
		return false;
	}
	for(int ii=now+1;ii<i;ii++){
		if(dfs(ii,lenn,nowlen+1,maxa,i,sum+a[ii])){
			ans=(ans+c[i-ii][lenn-nowlen])%mod;
			return false;
		}
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<=n;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}	
	if(a[n]==1){
		for(int i=4;i<=n;i++){
			ans=(ans+c[n][i])%mod;
		}
	} 
	else{
		for(int i=3;i<=n;i++){
			for(int j=1;j<i;j++){
				for(int l=1;j+l-1<i;l++){
					dfs(j,l,1,a[i],i,a[j]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

