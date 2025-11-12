#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010],answ,vis[5010],s=1,s2=1,an=1;
void dfs(int k,int maxn,int z,int ans){
	if(k>=3&&ans>maxn*2){
		answ++;
	}
	if(k>n) return ;
	for(int i=z+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,max(maxn,a[i]),i,ans+a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	if(n>250){
		for(int i=3;i<n;i++){
			s=1,s2=1;
			int t=min(i,n-i);
			for(int j=n;j>=n-t+1;j--){
				s=(s*j)%998244353;
			}
			for(int j=t;j>=1;j--) s2=(s2*j)%998244353;
			an=(an+s/s2)%998244353;
		}
		cout <<an%998244353;
	}
	else{
		dfs(0,0,0,0);
		cout <<answ%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
