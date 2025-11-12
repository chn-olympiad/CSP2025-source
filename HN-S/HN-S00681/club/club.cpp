#include<bits/stdc++.h>
using namespace std;
struct P{
	int n1, n2, n3, maxn, club;
};
struct Q{
	int number, grade;
};
bool cmp(Q a, Q b){
	if(a.grade > b.grade ){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club1.in", "r",stdin);
	freopen("club.out", "w", stdout);
	int t;
	cout << 1;
	cin >> t;
	for(; t >= 0; t --){
		P a[100001];
		Q m1[100001], m2[100001], m3[100001];
		int n, ans = 0, nn1 = 0, nn2 = 0, nn3 = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> a[i].n1 >> a[i].n2 >> a[i].n3;
			a[i].maxn = max(a[i].n1, max(a[i].n2, a[i].n3));
			if(a[i].n1 == a[i].maxn){
				a[i].club = 1;
				nn1 ++;
				m1[nn1].number = i;
				m1[nn1].grade = a[i].maxn;
			}
			else if(a[i].n2 == a[i].maxn){
				a[i].club = 2;
				nn2 ++;
				m2[nn2].number = i;
				m2[nn2].grade = a[i].maxn;
			}
			else{
				a[i].club = 3;
				nn3 ++;
				m3[nn3].number = i;
				m3[nn3].grade = a[i].maxn;
			}
		}
		if(nn1 > n / 2){
			sort(m1 + 1, m1 + 1 + nn1, cmp);
			while(nn1 <= n / 2){
				if(a[m1[nn1].number].n2 > a[m1[nn1].number].n3){
					nn2 ++;
					m2[nn2].number = m1[nn1].number;
					m2[nn2].grade = m1[nn1].grade;
				}
				else{
					nn3 ++;
					m3[nn3].number = m1[nn1].number;
					m3[nn3].grade = m1[nn1].grade;
				}
				nn1 --;
			}
			for(int i = 1; i <= nn1; i ++){
				ans += m1[i].grade;
			}
		}
		if(nn2 > n / 2){
			sort(m2 + 1, m2 + 1 + nn2, cmp);
			while(nn2 <= n / 2){
				nn3 ++;
				m2[nn2].number = m3[nn3].number;
				m2[nn2].grade = m3[nn3].grade;
				nn2 --;
			}
			for(int i = 1; i <= nn2; i ++){
				ans += m2[i].grade;
			}
		}
		if(nn3 > n / 2){
			sort(m3 + 1, m3 + 1 + nn3, cmp);
			while(nn3 <= n / 2){
				nn1 ++;
				m3[nn3].number = m1[nn1].number;
				m3[nn3].grade = m1[nn1].grade;
				nn3 --;
			}
		for(int i = 1; i <= nn3; i ++){
			ans += m1[i].grade;
		}
		cout << ans;
	}
	return 0;
}
// LOVE CCF
