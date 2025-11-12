//GZ-S00021  贵阳市第一中学  何傲杭 
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node{
	int a1, a2, a3;
}a[N],d[N];//第i个学生的满意度
bool vis[N][3];//第i个学生是否加入
int ma[N], se[N];//第i个学生满意度最大和次大 
int ma_[N], se_[N];//第i个学生满意度最大和次大的位置 
int T, n;  
bool Judge(){
	int ans1, ans2, ans3;
	ans1 = ans2 = ans3 = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i][1]) ans1++;
		if(ans1 > n/2) return 0;
		if(vis[i][2]) ans2++;
		if(ans2 > n/2) return 0;
		if(vis[i][3]) ans3++;
		if(ans3 > n/2) return 0;
	}
	return 1;
}
void Solve(){
	for(int i = 1; i <= n;){
		vis[i][ma_[i]] = 1;
		if(Judge()){
			i++;
		}else{
			vis[i][ma_[i]] = 0;
			vis[i][se_[i]] = 1;
			if(Judge()){
				i++;
			}else{
				vis[i][se_[i]] = 0;
				i--;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(ma, -1, sizeof(ma));
		memset(se, -1, sizeof(se));
		memset(ma_, 0, sizeof(ma_));
		memset(se_, 0, sizeof(se_));
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			d[i].a1 = a[i].a1, d[i].a2 = a[i].a2, d[i].a3 = a[i].a3;
			ma[i] = max(ma[i], max(a[i].a1, max(a[i].a2, a[i].a3)));
			if(a[i].a1 == ma[i]){
				a[i].a1 = -1;
				ma_[i] = 1;
			}else if(a[i].a2 == ma[i]){
				a[i].a2 = -1;
				ma_[i] = 2;
			}else{
				a[i].a3 = -1;
				ma_[i] = 3;
			}	
		}//求ma[]与位置 
		for(int i = 1; i <= n; i++){
			se[i] = max(se[i], max(a[i].a1, max(a[i].a2, a[i].a3)));
			if(a[i].a1 == se[i]){
				se_[i] = 1;
			}else if(a[i].a2 == se[i]){
				se_[i] = 2;
			}else{
				se_[i] = 3;
			}
		}//求se[]与位置 
		Solve();
		for(int i = 1; i <= n; i++){
			if(vis[i][1]) ans += d[i].a1;
			if(vis[i][2]) ans += d[i].a2;
			if(vis[i][3]) ans += d[i].a3;
		}
		cout << ans << endl;/*
		for(int i = 1; i <= n; i++){
			cout << vis[i][1] << " " << vis[i][2] << " " << vis[i][3] << endl;
		}*/
	}
	return 0;
}
