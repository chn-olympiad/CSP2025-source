#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],color[100010],vis[100010],ans;string s;
void dfs(int k){
	if (k==n+1){
		int sum=0;
		for (int i=1;i<=n;i++){
		//	cout <<color[i];
			if (sum>=a[color[i]]){
				sum++;
				continue;
			}
			if (s[i]=='0'){
				sum++;
			}
		}
		if (n-sum>=m)ans++;
		ans%=998244353;
	//	cout <<endl<<sum<<endl;
		return ;
		
	}
	for (int i=1;i<=n;i++){
		if (vis[i]==0){
			vis[i]=1;
			color[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin >>s;
	s='0'+s;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	dfs(1);
	cout <<ans;
	return 0;
}
