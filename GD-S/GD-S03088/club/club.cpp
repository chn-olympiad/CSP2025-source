#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 24;
int n,cnt;
struct info{
	int a[3],id;
}val[maxn];
int a[3][maxn],b[3][3][maxn];
int read(){
	int ans = 0;
	char c;
	while((c = getchar()) < '0' || c > '9');
	ans = (c ^ 48);
	while((c = getchar()) >= '0' && c <= '9'){
		ans = (ans << 1) + (ans << 3) + (c ^ 48);
	}
	return ans;
}
bool cmp(info a,info b){
	return a.a[cnt] > b.a[cnt];
}
bool cmpa(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
	return a > b;
}
bool cmpc(pair<int,int> a,pair<int,int> b){
	return a > b;
}
void solve(){
	n = read();
	pair<int,pair<int,int>> sum[3] = {{0,{0,0}},{0,{0,0}},{0,{0,0}}};
	for(int i = 1;i <= n;i++){
		a[0][i] = read();
		sum[0].first += a[0][i];
		sum[0].second.first += a[0][i] / 10000;	
		a[1][i] = read();
		sum[1].first += a[1][i];
		sum[1].second.first += a[0][i] / 10000;
		a[2][i] = read(); 
		sum[2].first += a[2][i];
		sum[2].second.first += a[0][i] / 10000;
		val[i].a[0] = a[0][i];
		val[i].a[1] = a[1][i];
		val[i].a[2] = a[2][i];
		val[i].id = i;
		b[0][1][i] = a[0][i] - a[1][i];
		b[0][2][i] = a[0][i] - a[2][i];
		b[1][0][i] = a[1][i] - a[0][i];
		b[1][2][i] = a[1][i] - a[2][i];
		b[2][0][i] = a[2][i] - a[0][i];
		b[2][1][i] = a[2][i] - a[1][i];
		b[0][0][i] = 1;
		b[1][1][i] = 1;
		b[2][2][i] = 1;
	} 
	sum[0].second.second = 0;
	sum[1].second.second = 1;
	sum[2].second.second = 2;
	sort(sum,sum + 3,cmpa);
	cnt = sum[0].second.second;
	sort(val + 1,val + 1 + n,cmp);
	long long s = 0,h = n / 2;
	for(int i = 1;i <= n / 2;i++){
		s += val[i].a[cnt];
//		cout << val[i].id << endl;
//		cout << val[i].a[cnt] << endl;
	}
	for(int i = n / 2 + 1;i <= n;i++){
		int x = val[i].id;
		if(b[cnt][0][x] < 0 || b[cnt][1][x] < 0 || b[cnt][2][x] < 0){
			int m = 0,id;
			for(int i = 0;i < 3;i++){
				if(i != cnt){
					if(m > b[cnt][i][x]){
						id = i;
						m = b[cnt][i][x];
					}
				}
			}
			s += a[id][x];
//			cout << x << endl;
			h--;
		}
	}
	if(!h){
		cout << s << endl;
		return;
	}
	else{
		vector<pair<int,int>> m1,m2;
		for(int i = 1;i <= n / 2;i++){
			int x = val[i].id;
			int k = INT_MAX;
			for(int j = 0;j < 3;j++){
				if(j != cnt){
					k = min(b[cnt][j][x],k);
				}
			} 
			m1.push_back({k,i});
		} 
		sort(m1.begin(),m1.end());
		for(int i = n / 2 + 1;i <= n;i++){
			int x = val[i].id;
			if(b[cnt][0][x] >= 0 && b[cnt][1][x] >= 0 && b[cnt][2][x] >= 0){
				int k = INT_MAX;
				for(int j = 0;j < 3;j++){
					if(j != cnt){
						k = min(b[cnt][j][x],k);
					}
				}
				m2.push_back({k,i});
			}
		}
		sort(m2.begin(),m2.end(),cmpc);
		int j = 0;
		for(auto i : m2){
			if(m1[j].first > i.first){
				int maxm = INT_MIN;
//				cout << val[i.second].id << endl; 
				for(int k = 0;k < 3;k++){
					if(k != cnt){
						maxm = max(maxm,a[k][val[i.second].id]);
					} 
				}
//				cout << maxm << endl;
//				cout << i.first << endl;
				s += maxm;
			}
			else{
				int maxm = 0;
				s -= a[cnt][val[m1[j].second].id];
				for(int k = 0;k < 3;k++){
					if(k != cnt){
						maxm = max(maxm,a[k][val[m1[j].second].id]);
					}
				}
//				cout << maxm << endl;
//				cout << m1[j].first << endl;
				s += maxm;
				s += a[cnt][val[i.second].id];
				j++;
			}
		}
		cout << s << endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	T = read();
	while(T--){
		solve();
	}
	return 0;
} 
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

*/
