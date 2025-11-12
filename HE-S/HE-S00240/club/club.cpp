//不会，试着骗几分 
#include <bits/stdc++.h>
using namespace std;
struct student{
	int a1, a2, a3;
}Stu[12312399];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	/////////////////////////////////////////////////////////////////
	int l;
	cin >> l;
	for(int d_th = 1; d_th <= l; d_th++){
		int n;
		cin >> n;
		double limit = n / 2;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> Stu[i].a1 >> Stu[i].a2 >> Stu[i].a3;
			ans += max(Stu[i].a3, max(Stu[i].a1, Stu[i].a2));
		}
		cout << ans << endl;
	}
	/////////////////////////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}
