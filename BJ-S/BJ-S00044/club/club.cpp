#include<bits/stdc++.h>
using namespace std;
int n,q;
int sum[4],a[200005][5],ans;
void DFS(int i,int num){
	if(i == n+1){
		ans = max(ans,num);
		return;
	}
	if(sum[1] < n/2){
		sum[1]++;
		DFS(i+1,num+a[i][1]);
		sum[1]--;
	}
	if(sum[2] < n/2){
		sum[2]++;
		DFS(i+1,num+a[i][2]);
		sum[2]--;
	}
	if(sum[3] < n/2){
		sum[3]++;
		DFS(i+1,num+a[i][3]);
		sum[3]--;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> q;
	while(q--){
		cin >> n;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		DFS(1,0);
		cout << ans << endl;
	}
	return 0;
}
/*

3 4 5  5
4 3 5  5
3 4 5  5
5 3 1  5

*/