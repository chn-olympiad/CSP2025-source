#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5010;
int a[N],n;
int c[N][N];
int baoli(int nn,int maxn,int sum,int geshu){
	if(nn>n+1)return 0;
	int x=1;
	if(geshu<3)x=0;
	if(sum<=2*maxn)x=0;
	if(x==1){
		return (x+baoli(nn+1,max(maxn,a[nn]),sum+a[nn],geshu+1))%mod;
	}
	else{
		return (x+baoli(nn+1,max(maxn,a[nn]),sum+a[nn],geshu+1)+baoli(nn+1,maxn,sum,geshu))%mod;
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return false;
	}
	return true;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check()){
		c[1][1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==1)c[i][j]=1;
				else c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
		}
		int ans=0;
		for(int i=4;i<=n;i++)ans=(ans+c[n][i])%mod;
		cout<<ans%mod;
	}
	else cout<<baoli(1,0,0,0)%mod;
	return 0;
}
