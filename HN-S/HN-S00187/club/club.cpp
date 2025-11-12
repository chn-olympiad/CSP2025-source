#include <bits/stdc++.h>
using namespace std;
int t,n,maxn=0;
long long cnt;
int a[100002][5];
bool vis[100002][5];
void dfs(int now){
	if (now>n+1){
		int list[4]={0,0,0,0};
		long long ans=0;
		for (int i=1;i<=n;i++){
			if (list[1]>n/2 || list[2]>n/2 || list[3]>n/2) return;
			for (int j=1;j<=3;j++){
				if (vis[i][j]){
					ans+=a[i][j];
					//cout << a[i][j] << ' ';
					list[j]++;
				}
			} 
		}
		if (list[1]>n/2 || list[2]>n/2 || list[3]>n/2) return;
		//cout << endl;
		cnt=max(cnt,ans);
		return;
	}
	for (int i=1;i<=3;i++){
		vis[now][i]=1;
		dfs(now+1);
		vis[now][i]=0;
	}
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			//cnt+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		// n/2
		dfs(1);
		cout << cnt << "\n";
		cnt=0;
	}
	return 0;
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
