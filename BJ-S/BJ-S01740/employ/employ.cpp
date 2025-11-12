#include <bits/stdc++.h>
using namespace std;

char dif[10010];
int n,m;
bool vis[10010];
int a[100010];
int w[100010];
bool check(){
	int canc = 0;//被拒绝人数
	int OK = 0;
	for(int i = 1;i <= n;i++){
		if(canc >= a[w[i]])canc++;
		else if(dif[i] == '0'){
			canc++;
		}
		else OK++;
	}
	if(OK >= m){
		return 1;
	}
	return 0;
}

int ans = 0;
void dfs(int step){
	if(step > n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i = 1;i <= n;i++){//枚举前来面试的人
		if(!vis[i]){
			vis[i] = 1;
			w[step] = i;
			dfs(step+1);
			vis[i] = 0;
			w[step] = 0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> dif[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
