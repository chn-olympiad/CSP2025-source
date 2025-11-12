#include<bits/stdc++.h>
using namespace std;
int mg[5100];
int ans_ = 0;
void two(int * ro, int i, int max_, int ans, int n){
	if(i >= n){
		if(ans > max_ * 2){
			ans_ ++;
		}
		return;
	}else{
		two(ro, i + 1, max(max_, ro[i]), ans + ro[i], n);
		two(ro, i + 1, max_, ans, n);
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> mg[i];
	}
	sort(mg, mg + n);
	two(mg, 0, 0, 0, n);
	cout << ans_;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
