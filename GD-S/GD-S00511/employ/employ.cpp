#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],vis[15],c[505];	
int ans[15];
int block[4000005][15],bot;
void dfs(int step,int ans[15]){
	if(step==n+1){
		bot++;
		for(int i=1;i<=n;i++){
			block[bot][i]=ans[i];
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			ans[step]=i;
			vis[i]=1;
			dfs(step+1,ans);
			vis[i]=0;
		}
	}
}
bool check(int x){
	int failt=0,suc=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0||failt>=c[block[x][i]]){
			failt++;
		}else{
			suc++;
		}
	}
	if(suc>=m){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		a[i]=(s[i-1]-'0');
		cin >> c[i];
	}
	if(n<=10){
		int res=0;
		dfs(1,ans);
		for(int i=1;i<=bot;i++){
			if(check(i)){
				res++;
			}
		}
		cout << res; 
	}else{
		cout <<0;
	}
	
	return 0;
} 
