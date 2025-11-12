#include <bits/stdc++.h>
using namespace std;
struct node{
	int l1;
	int l2;
	int l3;
	int club;
	int num;
	int club2;
	int num2;
}a[100005];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, t;
	cin >> t;
	while(t--){
		int cl[3] = {};
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].l1 >> a[i].l2 >> a[i].l3;
			if(a[i].l1 > a[i].l2 && a[i].l1 >  a[i].l3){
				a[i].club = 1;
				a[i].num = a[i].l1;
				if(a[i].l2 > a[i].l3){
					a[i].club2 = 2;
					a[i].num2 = a[i].l2;
				}else{
					a[i].club2 = 3;
					a[i].num2 = a[i].l3;
				}
			}else if(a[i].l2 > a[i].l1 && a[i].l2 > a[i].l3){
				a[i].club = 2;
				a[i].num = a[i].l2;
				if(a[i].l1 > a[i].l3){
					a[i].club2 = 1;
					a[i].num2 = a[i].l1;
				}else{
					a[i].club2 = 3;
					a[i].num2 = a[i].l3;
				}
			}else{
				a[i].club = 3;
				a[i].num = a[i].l3;
				if(a[i].l1 > a[i].l2){
					a[i].club2 = 1;
					a[i].num2 = a[i].l1;
				}else{
					a[i].club2 = 2;
					a[i].num2 = a[i].l2;
				}
			}
		}
		int ans = 0;
		int max_people = n / 2;
		for(int i = 1; i <= n; i++){
			if(cl[a[i].club] <= max_people){
				cl[a[i].club]++;
				ans += a[i].num;
			}else{
				cl[a[i].club2]++;
				ans += a[i].num2;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
