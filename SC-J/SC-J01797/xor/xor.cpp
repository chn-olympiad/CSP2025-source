#include <bits/stdc++.h>
using namespace std;

int a[500010];
int l[500010], r[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cur = 0;
	for (int i = 1; i <= n; i++){
		int last = a[i];
		if (a[i] == k){
			l[++cur] = r[cur] = i;
			continue;
		}
		for (int j = i + 1; j <= n; j++){
			last = last ^ a[j];
			if (last == k){
				l[++cur] = i;
				r[cur] = j;	
				break;	
			}
		}
	}
	int cnt =0;
	for (int i = 1; i <= n; i++){
		int minn = 600000, op = 1;
		bool flag = 0;
		for (int j = 1; j <= cur; j++){
			if (r[j] < minn && l[j] >= i){
				minn = r[j];
				flag = 1;
			}
		}
		if (flag){
			cnt++;
		}
		i = minn;
	}
	cout << cnt << endl;
	return 0;
}