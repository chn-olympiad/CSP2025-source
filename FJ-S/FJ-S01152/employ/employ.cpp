#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,z,c[505],dp[505][505];
bool a[505],b[505];
int d[505];
void dfs(int k,int f){
	if(n-f>=m)return;
	if(k==n){
		for(int i=1;i<=k;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;
		if(n-f>=m)z=(z+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1)continue;
		d[k+1]=i;
		b[i]=1;
		if(f>=c[i]||a[k+1]==0)dfs(k+1,f+1);
		else dfs(k+1,f);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		sort(c+1,c+1+n);
		if(c[n]==0)cout<<0<<endl;
		else{
			z=1;
			for(int i=1;i<=n;i++){
				z=(z*i)%mod;
			}
			cout<<z<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			d[1]=i;
			b[i]=1;
			if(c[i]==0||a[1]==0)dfs(1,1);
			else dfs(1,0);
			b[1]=0;
		}
		cout<<z<<endl;
	}
//	else{
////		for(int i=1;i<=n;i++){
////			for(int j=0;j<=n;j++){
//				if(a[i]==1){
//					for(int k=1;k<=n;k++){
//						dp[i][j]=dp[i-1][j-1]
//					}
//				}
//				else{
//					for(int k=1;)
//				}
//			}
//		}
//	}
}
