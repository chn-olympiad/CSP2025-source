#include <bits/stdc++.h>
using namespace std;


int n,m,arr[510];
//string s;
int s[510];
long long ans;
bool vis[510];

long long sum(int x){
	if(x > 1) return x * sum(x - 1) % 998244353;
	else return x;
}

void dfs(int id,int day,int num,int w){
	if(num >= m){
		ans += sum(n - num) % 998244353;
		ans %= 998244353;
		return;
	}
	vis[id] = 1;
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		//printf("%d %d\n",id,s[day]);
		if(s[day] == 1 && arr[i] > w){
			dfs(i,day + 1,num + 1,w);
		}else{
			dfs(i,day + 1,num,w + 1);
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 0;i <= n;i++){
		s[i] = getchar() - 48;
	}
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof vis);
		dfs(i,1,0,0);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
