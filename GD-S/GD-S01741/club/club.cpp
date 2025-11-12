#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tt,n,a[100010][5];
ll ans;

int vis[100010];
ll t [5];
void dfs(int x){
	if(x > n){
		ll cnt = 0;
		if(t[1] > n / 2 || t[2] > n / 2 || t[3] > n / 2){
			return;
		}
		for(int i = 1;i <= n;i++){
			cnt += a[i][vis[i]];
		}
		ans = max(cnt,ans);
		return;
	}
	for(int i = 1;i <= 3;i++){
		vis[x] = i;
		t[i]++;
		dfs(x+1);
		t[i]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--){
		cin>>n;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			t[i] = 0;
			vis[i] = 0;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

