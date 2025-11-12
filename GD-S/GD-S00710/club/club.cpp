#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N][4],sum[4];
int n;

int dfs(int t){
	if(t == n + 1) return 0;
	int ans = 0;
	for(int i = 1;i <= 3;i ++){
		if(sum[i] < n / 2){
			sum[i] ++;
			ans = max(ans,dfs(t + 1) + a[t][i]);
			sum[i] --;
		}
	}
	return ans;
}

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	while(t --){
		cin >> n;
		bool flag = 0;
		bool falg = 0;
		for(int i = 1;i <= n;i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] != 0 or a[i][3] != 0) flag = 1;
			if(a[i][3] != 0) falg = 1;
		}
		if(n <= 10){
			memset(sum,0,sizeof sum);
			memset(a,0,sizeof a);
			cout << dfs(1) << endl;
		} else if(flag == 0){
			vector<int> s;
			for(int i = 1;i <= n;i ++) s.push_back(a[i][1]);
			sort(s.begin(),s.end(),cmp);
			int ans = 0;
			for(int i = 0;i < n / 2;i ++){
				ans += s[i];
			}
			cout << ans << endl;
		} else {
			int ans = 0;
			for(int i = 1;i <= n;i ++){
				int maxk,maxx = 0;
				for(int j = 1;j <= 3;j ++){
					if(a[i][j] > maxx and sum[j] < n / 2){
						maxk = j;
						maxx = a[i][j];
					}
				}
				ans += maxx;
				sum[maxk] ++;
			}
			cout << ans << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
