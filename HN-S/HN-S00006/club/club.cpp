#include<bits/stdc++.h>
using namespace std;
struct node{
//	int x,i;
//	bool operator<(const &node ,other)const{
//		return x < other.x;
//	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		int a[n + 1],b[n + 1],c[n + 1];
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		priority_queue<pair<int,int> > q1,q2,q3;
		int cnt = 0,cnt1 = 0,cnt2 = 0;
		int full = -1;int res = 0;
		for(int i = 1;i <= n;i++){
			if(cnt >= (n / 2)){
				full = 1;
			}else if(cnt1 >= (n / 2)){
				full = 2;
			}else if(cnt2 >= (n / 2)){
				full = 3;
			}
			if(a[i] > b[i] && a[i] > c[i]){
				if(full != 1){
					res += a[i];
					q1.push({-(a[i]),i});
					cnt++;
				}else{
//					if(a[i] > abs(q1.top().first)){
						int u = q1.top().second;
						if(res + max(b[i],c[i]) > res + a[i] - a[u] + max(b[u],c[u])){
							res += max(b[i],c[i]);
						}
						else if(res + a[i] - a[u] + max(b[u],c[u]) >= res){
							q1.pop();
							q1.push({-(a[i]),i});
							res += a[i];
							res -= a[u];
							res += max(b[u],c[u]);
							if(c[u] > b[u]){
								q1.push({-(c[u]),u});
								cnt2++;
							}else{
								q2.push({-b[u],u});
								cnt1++;
							}
						}
						
//					}
				}
			}else if(b[i] >= a[i] && b[i] >= c[i]){
				if(full != 2){
					res += b[i];
					q2.push({-(b[i]),i});
					cnt1++;
				}else{
//					if(b[i] > abs(q2.top().first)){
						int u = q2.top().second;
						if(res + max(a[i],c[i]) > res + b[i] - b[u] + max(a[u],c[u])){
							res += max(a[i],c[i]);
						}
						else if(res + b[i] - b[u] + max(a[u],c[u]) >= res){
							q2.pop();
							q2.push({-(b[i]),i});
							res += b[i];
							res -= b[u];
							res += max(a[u],c[u]);
							if(a[u] > c[u]){
								q1.push({-(a[u]),u});
								cnt++;
							}else{
								q2.push({-c[u],u});
								cnt2++;
							}
						}
						
//					}
				}
			}else if(c[i] >= b[i] && c[i] >= a[i]){
				if(full != 3){
					res += c[i];
					q3.push({-(c[i]),i});
					cnt2++;
				}else{
//					if(c[i] > abs(q3.top().first)){
						int u = q3.top().second;
						if(res + c[i] - c[u] + max(a[u],b[u]) <= res + max(b[i],c[i])){
							res += max(b[i],c[i]);
						}
						else if(res + c[i] - c[u] + max(a[u],b[u]) >= res){
							q3.pop();
							q3.push({-(c[i]),i});
							res += c[i];
							res -= c[u];
							res += max(a[u],b[u]);
							if(a[u] > b[u]){
								q1.push({-(a[u]),u});
								cnt++;
							}else{
								q2.push({-b[u],u});
								cnt1++;
							}
						}
//						
//					}
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}
