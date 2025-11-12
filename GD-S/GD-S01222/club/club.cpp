#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n, t, ans;
int a[maxn][4];
bool vis[maxn];
int pos[4];
void f(int i, int num){
	if(i==n+1){
		ans=max(ans, num);
		return ;
	}
	for(int j=1;j<=n;j++){
		if(vis[j]) continue;
		vis[j]=1;
		for(int k=1;k<=3;k++){
			if(pos[k]>=n/2) continue;
			pos[k]++;
			f(i+1, num+a[j][k]);
			pos[k]--;
		}
		vis[j]=0;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
		}
		f(1, 0);
		cout<<ans<<endl;
	}
	
	
	return 0;
}
