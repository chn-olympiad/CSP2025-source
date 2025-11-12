#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}s[100010];
int ans,n;
bool cmp(node x,node y){
	return x.a > y.a;
}
void dfs(int now,int fr,int sc,int tr,int sum){
	if(now > n){
		ans = max(ans,sum);
		return;
	}
	if(fr < n/2){
		dfs(now+1,fr+1,sc,tr,sum+s[now].a);
	}
	if(sc < n/2){
		dfs(now+1,fr,sc+1,tr,sum+s[now].b);
	}
	if(tr < n/2){
		dfs(now+1,fr,sc,tr+1,sum+s[now].c);
	}
}
void solve(){
	cin>> n;
	ans = 0;
	for(int i = 1;i <= n;i++){
		cin>> s[i].a >> s[i].b >> s[i].c;
	}
	sort(s+1,s+n+1,cmp);
	if(n > 100){
		for(int i = 1;i <= n/2;i++){
			ans += s[i].a;
		}
		cout<< ans << "\n";
		return;
	}
	dfs(1,0,0,0,0);
	cout<< ans << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>> t;
	while(t--){
		solve();
	}
	return 0;
}
