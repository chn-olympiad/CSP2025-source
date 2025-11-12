#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 5;
int T , n;
int sum[5] , cnt[5];
struct node{
	int f , s , t;
	int mx , mxi;
	int sumsum;
}a[MAXN];
bool cmp(node pre , node nxt){return pre.sumsum < nxt.sumsum;}
void update(){
	sum[1] = 0; sum[2] = 0; sum[3] = 0;
	cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;
	return;
}
void solve(){
	update(); cin >> n;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d%d" , &a[i].f , &a[i].s , &a[i].t);
		a[i].mx = max(a[i].f , max(a[i].s , a[i].t));
		a[i].sumsum = a[i].f + a[i].s + a[i].t;
		if(a[i].f == a[i].mx) a[i].mxi = 1;
		else if(a[i].s == a[i].mx) a[i].mxi = 2;
		else if(a[i].t == a[i].mx) a[i].mxi = 3;
	}
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1 ; i <= n ; i++){
		if(a[i].mxi == 1){
			if(sum[1] + 1 <= n / 2){
				cnt[1] += a[i].f;
				sum[1]++;
			}
			else{
				if(a[i].s > a[i].t){
					cnt[2] += a[i].s;
					sum[2]++;
				}
				else{
					cnt[3] += a[i].t;
					sum[3]++;
				}
			}
		}
		else if(a[i].mxi == 2){
			if(sum[2] <= n / 2){
				cnt[2] += a[i].s;
				sum[2]++;
			}
			else{
				if(a[i].f > a[i].t){
					cnt[1] += a[i].f;
					sum[1]++;
				}
				else{
					cnt[3] += a[i].t;
					sum[3]++;
				}
			}
		}
		else if(a[i].mxi == 3){
			if(sum[3] <= n / 2){
				cnt[3] += a[i].t;
				sum[3]++;
			}
			else{
				if(a[i].s > a[i].f){
					cnt[2] += a[i].s;
					sum[2]++;
				}
				else{
					cnt[1] += a[i].f;
					sum[1]++;
				}
			}
		}
	}
	cout << cnt[1] + cnt[2] + cnt[3] << '\n';
	return;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
