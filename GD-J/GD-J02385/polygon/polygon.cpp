#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n;
int arr[N]; 
int ans = 0;
bool vis[N];
int cns[N];

//void dfs(int k, int cnt, int maxn, int sum){
////	cout << k << ' ' << cnt << ' ' << maxn << ' ' << sum << endl;
////	cout << " | ";
////	for (int i = 1; i <= cnt; i ++){
////		cout << cns[i] << ' ';
////	}
////	cout << endl;
//	if (k > n + 1) return;
//	if (cnt >= 3 && sum > maxn * 2){
//		cout << k << ' ' << cnt << ' ' << maxn << ' ' << sum << endl;
//		cout << " | ";
//		for (int i = 1; i <= cnt; i ++){
//			cout << cns[i] << ' ';
//		}
//		cout << endl; 
//		ans ++;
//	}
//	for (int i = k; i <= n; i ++){
//		if (!vis[i] && cns[k - 1] < arr[i]){
//			vis[i] = 1;
//			cns[k] = arr[i];
//			dfs(k + 1, cnt + 1, max(maxn,arr[i]), sum + arr[i]);
//			vis[i] = 0;
//		}
//	}
//}

void dfs(int k, int cnt, int maxn, int sum){
//	cout << k << ' ' << cnt << ' ' << maxn << ' ' << sum << endl;
	if (k > n + 1) return;
	if (cnt >= 4 && sum > maxn * 2){
//		cout << k << ' ' << cnt << ' ' << maxn << ' ' << sum << endl;
//		cout << " | ";
//		for (int i = 1; i < cnt; i ++){
//			cout << cns[i] << ' ';
//		}
//		cout << endl; 
		ans ++;
	}
//	cout << "||||||";
//	for (int i = 1; i < cnt; i ++){
//		cout << cns[i] << ' ';
//	}
//	cout << endl; 
//	cout << endl; 
	for (int i = cns[cnt - 1] + 1; i <= n; i ++){
		if (!vis[i]){
			// && arr[cns[cnt - 1]] <= arr[i]
			vis[i] = 1;
			cns[cnt] = i;
			dfs(i + 1, cnt+1, max(maxn, arr[i]), sum + arr[i]);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> arr[i];
	}
	dfs(0,1,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
