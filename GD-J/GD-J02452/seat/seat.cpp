#include<bits/stdc++.h>
using namespace std;
bool rule(int a, int b){
	return a > b;
}
int main(){
	//task seat (Accepted)
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m; 
	if (n == 1&&m == 1){
		cout << 1 << " " << 1;
	}
	const int N = n*m;
	vector<int> a(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
	}
	int score = a[0];
	sort(a.begin(),a.end(),rule);
	int l = 0, r = N-1;
	int mid = (l+r) >> 1;
	while (l < r){
		mid = (l+r) >> 1;
		if (a[mid] > score) l = mid+1;
		else if(a[mid] < score) r = mid;
		else break;
	}
	mid++;
	if (mid <= n){
		cout << 1 << " " << mid;
		return 0;
	}
	int c = mid/n, c1 = mid%n;
	if (c1 != 0) c++;
	if (c % 2 == 0) c1 = n - mid%n +1;
	else c1 = mid%n;
	cout << c << " " << c1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
