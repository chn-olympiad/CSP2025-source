#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m,n;
	scanf("%d %d", &n, &m);
	vector<int> s;
	int x;
	for(int i = 0;i<m*n;i++){
		scanf("%d", &x);
		s.push_back(x);
	}
	int a1 = s[0];
	sort(s.begin(), s.end());
	int l=0,r=m*n;
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if (s[mid] == a1){
			l = mid;
			break;
		}else if(s[mid] > a1){
			r = mid;
		}else{
			l = mid;
		}
	}
	x = m*n-(l+r)/2;
	int c = x/m;
	int j = x%n;
	if(c%2==1) j = n - j;
	printf("%d %d", c+1,j+1);
	return 0;
}
