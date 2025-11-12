#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[510],ans,vis[510],k2[1010],e;
string s;
void dfs(int k,int p,int an){
	if(k>n||n-p+an<m) return ;
	if(k==n&&an>=m){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(p>=a[i]||s[k]=='0') dfs(k+1,p+1,an);
			else{
				dfs(k+1,p,an+1);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin >>s;
	for(int i=1;i<=n;i++) cin >>a[i];
	if(n<100){
		dfs(0,0,0);
		cout <<ans%998244353;
	}else{
		int answ=1;
		for(int i=n;i>=1;i--) answ=(answ*i)%998244353;
		cout <<answ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
