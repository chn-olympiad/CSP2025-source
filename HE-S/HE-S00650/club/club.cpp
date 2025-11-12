#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int takemax(int a, int b, int c){
	if (a >= b && a >= c)return 0;
	if (b >= a && b >= c)return 1;
	return 2;
}
int takemax2(int a, int b, int c){
	if (a <= b && a >= c)return 0;
	if (a >= b && a <= c)return 0;
	if (b <= a && b >= c)return 1;
	if (b >= a && b <= c)return 1;
	return 2;
}
bool cmp(vector<int> a, vector<int> b){
	return a[a[3]] - a[a[4]] < b[b[3]] - b[b[4]];
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	for (cin >> T; T; T--){
		int n;
		cin >> n;
		vector<vector <int> > a(n, vector<int>(5));
		vector <int> maxi(3);
		long long sum = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			a[i][3] = takemax(a[i][0], a[i][1], a[i][2]);
			a[i][4] = takemax2(a[i][0], a[i][1], a[i][2]);
			maxi[a[i][3]]++;
			sum += a[i][a[i][3]];
		}
		sort(a.begin(), a.end(), cmp);
		int maxid = takemax(maxi[0], maxi[1], maxi[2]);
		for (int i = 0; maxi[maxid] > n / 2; i++){
			if (a[i][3] != maxid)continue;
			sum -= a[i][a[i][3]] - a[i][a[i][4]];
			maxi[maxid]--;
		}
		cout << sum << endl;
	}
	return 0;
}
