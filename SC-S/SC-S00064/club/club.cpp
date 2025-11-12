#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, A[N], a[N][10];


bool cmp(int& A, int& B){
	return A > B;
} 

int dfs(int sum, int pos){
	if(pos > n) return sum;
	return max(dfs(sum+a[pos][1], pos+1), 
			max(dfs(sum+a[pos][2], pos+1),
			dfs(sum+a[pos][3], pos+1)));
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T--){
		bool pd = true;
		cin >> n;
		for(int i=1;i<=n;++i){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			A[i] = a[i][1]; 
			if(a[i][2] != 0 || a[i][3] != 0) pd = false;
		}
		if(pd){
			sort(A+1, A+n+1, cmp);
			int ans = 0;
			for(int i=1;i<=n/2;++i){
				ans += A[i];
			}
			cout << ans << endl;
		}
		else{
			cout << dfs(0, 1) << endl;
		}
	}
	
	return 0;
}