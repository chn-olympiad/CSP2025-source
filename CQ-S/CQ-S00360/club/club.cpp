#include<bits/stdc++.h>
using namespace std;
int r[100010][4],cnt[4];
int n;
int dfs(int i,int j){ 
	if(i == n) return r[i][j];
	cnt[j] ++;
	int a=-1,b=-1,c=-1;
	if(cnt[1] <= (n/2-1)){
		a = dfs(i+1,1);
	}
	if(cnt[2] <= (n/2-1)){
		b = dfs(i+1,2);
	}
	if(cnt[3] <= (n/2-1)){
		c = dfs(i+1,3);
	}
	cnt[j] --;
	return max(max(max(a,b),c),0) + r[i][j];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1 ;j <= 3;j++){
				cin >>r[i][j];
			}
		}
		cout <<max(max(dfs(1,1),dfs(1,2)),dfs(1,3))<<endl;
	}
	return 0;
} 
