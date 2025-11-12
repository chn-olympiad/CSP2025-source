#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
int n,t,ans,cnt[5];
void dfs(int step,int s1,int s2,int s3){
	if(step > n){
		ans = max(ans,s1 + s2 + s3);
		return;
	}
	if(cnt[1] < n / 2){
		cnt[1]++;
		dfs(step + 1,s1 + a[step].a,s2,s3);
		cnt[1]--;
	}
	if(cnt[2] < n / 2){
		cnt[2]++;
		dfs(step + 1,s1,s2 + a[step].b,s3);
		cnt[2]--;
	}
	if(cnt[3] < n / 2){
		cnt[3]++;
		dfs(step + 1,s1,s2,s3 + a[step].c);
		cnt[3]--;
	}
}
void input(){
	cin >> t;
	while(t--){
		cin >> n; ans = 0;
		for(int i = 1;i <= n;++i) cin >> a[i].a >> a[i].b >> a[i].c;
		dfs(1,0,0,0);
		cout << ans << "\n";
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0);
	input();
	return 0;
}
