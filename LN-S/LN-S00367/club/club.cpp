#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N][4];
int n;
int ans;
void dfs(int u,int ac,int bc,int cc,int val){
	if(ac>n/2||bc>n/2||cc>n/2){
		return;
	}
	if(ac+bc+cc==n){
		ans=max(ans,val);
		return;
	}
	dfs(u+1,ac+1,bc,cc,val+arr[u][1]);
	dfs(u+1,ac,bc+1,cc,val+arr[u][2]);
	dfs(u+1,ac,bc,cc+1,val+arr[u][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		ans=0;
		memset(arr,0,sizeof arr);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> arr[i][j];
			}
		}
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	return 0;
}
