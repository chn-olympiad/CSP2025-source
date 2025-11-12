#include<bits/stdc++.h>
using namespace std;
int n,m,c[150],ans;
string a;
bool vis[150];
void dfs(int nx,int cnt,int dep){
	if(dep > n){
		if(cnt >= m){
			ans++;
			return ;
		}
		
	}
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			vis[j] = 1;
			if(c[j] > dep || c[j] > nx || a[dep]=='0'){
				nx++;
			}
			else{
				cnt++;
			}
			dfs(nx,cnt,dep+1);
			vis[j] = 0;
			if(c[j] > dep || c[j] > nx || a[dep]=='0'){
				nx--;
			}
			else{
				cnt--;
			}
			
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> a;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	dfs(0,0,1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
/*
3 2
101
1 1 2
*/

