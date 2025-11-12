#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
int qwq,n,a[5],cnt[5];
priority_queue<int> q[5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> qwq;
	while(qwq--){
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1;i <= 3;i++){
			while(!q[i].empty())q[i].pop();
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[1] >> a[2] >> a[3];
			int pos = max_element(a + 1,a + 4) - a;
			int pos2 = 0;
			for(int j = 1;j <= 3;j++){
				if(j != pos && a[j] >= a[pos2])pos2 = j;
			}
			if(cnt[pos] != n / 2){
				cnt[pos]++,ans += a[pos];
				q[pos].push(a[pos2] - a[pos]);
			}else{
				int val1 = a[pos] + q[pos].top(),val2 = a[pos2];
				if(val1 > val2){
					q[pos].pop(),ans += val1;
					q[pos].push(a[pos2] - a[pos]);
				}else ans += val2;
			}
		}
		cout << ans << endl;
	}
} 
