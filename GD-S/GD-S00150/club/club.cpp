//18 

#include<iostream>
#include<algorithm>
using namespace std;

int t;
bool flag,falg;
int n,aans;
int a[3][100005];
int cnt[3];

void dfs(int x,int ans){
	if (x > n){
		aans = max(aans,ans);
		return;
	}
	if (cnt[0] < n / 2){
		cnt[0]++;
		dfs(x+1,ans + a[0][x]);
		cnt[0]--;
	}
	if (cnt[1] < n / 2){
		cnt[1]++;
		dfs(x+1,ans + a[1][x]);
		cnt[1]--;
	}
	if (cnt[2] < n / 2){
		cnt[2]++;
		dfs(x+1,ans + a[2][x]);
		cnt[2]--;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		flag= true;
		aans = 0;
		for (int i = 1;i <= n;i++){
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			if (a[2][i] or a[1][i]){
				flag = false;
			}
		}
		if (flag){
			sort(a[0]+1,a[0]+n+1);
			for (int i = n;i >= n / 2 + 1;i--){
				aans += a[0][i];
			}
			cout << aans << endl;
			continue;
		}
		dfs(1,0);
		cout << aans << endl;
	}
}

// 37 

